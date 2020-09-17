// Copyright 2020 The Chromium Embedded Framework Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "libcef/browser/browser_host_base.h"

#include "libcef/browser/browser_info_manager.h"
#include "libcef/browser/image_impl.h"
#include "libcef/browser/navigation_entry_impl.h"
#include "libcef/browser/net/scheme_handler.h"
#include "libcef/browser/thread_util.h"

#include "base/logging.h"
#include "chrome/browser/spellchecker/spellcheck_factory.h"
#include "chrome/browser/spellchecker/spellcheck_service.h"
#include "components/favicon/core/favicon_url.h"
#include "components/spellcheck/common/spellcheck_features.h"
#include "content/public/browser/browser_context.h"
#include "content/public/browser/download_manager.h"
#include "content/public/browser/download_request_utils.h"
#include "content/public/browser/navigation_entry.h"
#include "ui/gfx/image/image_skia.h"

#if defined(OS_MAC)
#include "components/spellcheck/browser/spellcheck_platform.h"
#endif

namespace {

// Associates a CefBrowserHostBase instance with a WebContents. This object will
// be deleted automatically when the WebContents is destroyed.
class WebContentsUserDataAdapter : public base::SupportsUserData::Data {
 public:
  static void Register(CefRefPtr<CefBrowserHostBase> browser) {
    new WebContentsUserDataAdapter(browser);
  }

  static CefRefPtr<CefBrowserHostBase> Get(
      const content::WebContents* web_contents) {
    WebContentsUserDataAdapter* adapter =
        static_cast<WebContentsUserDataAdapter*>(
            web_contents->GetUserData(UserDataKey()));
    if (adapter)
      return adapter->browser_;
    return nullptr;
  }

 private:
  WebContentsUserDataAdapter(CefRefPtr<CefBrowserHostBase> browser)
      : browser_(browser) {
    auto web_contents = browser->GetWebContents();
    DCHECK(web_contents);
    web_contents->SetUserData(UserDataKey(), base::WrapUnique(this));
  }

  static void* UserDataKey() {
    // We just need a unique constant. Use the address of a static that
    // COMDAT folding won't touch in an optimizing linker.
    static int data_key = 0;
    return reinterpret_cast<void*>(&data_key);
  }

  CefRefPtr<CefBrowserHostBase> browser_;
};

}  // namespace

// static
CefRefPtr<CefBrowserHostBase> CefBrowserHostBase::GetBrowserForHost(
    const content::RenderViewHost* host) {
  DCHECK(host);
  CEF_REQUIRE_UIT();
  content::WebContents* web_contents = content::WebContents::FromRenderViewHost(
      const_cast<content::RenderViewHost*>(host));
  if (web_contents)
    return GetBrowserForContents(web_contents);
  return nullptr;
}

// static
CefRefPtr<CefBrowserHostBase> CefBrowserHostBase::GetBrowserForHost(
    const content::RenderFrameHost* host) {
  DCHECK(host);
  CEF_REQUIRE_UIT();
  content::WebContents* web_contents =
      content::WebContents::FromRenderFrameHost(
          const_cast<content::RenderFrameHost*>(host));
  if (web_contents)
    return GetBrowserForContents(web_contents);
  return nullptr;
}

// static
CefRefPtr<CefBrowserHostBase> CefBrowserHostBase::GetBrowserForContents(
    const content::WebContents* contents) {
  DCHECK(contents);
  CEF_REQUIRE_UIT();
  return WebContentsUserDataAdapter::Get(contents);
}

// static
CefRefPtr<CefBrowserHostBase> CefBrowserHostBase::GetBrowserForFrameTreeNode(
    int frame_tree_node_id) {
  // Use the thread-safe approach.
  auto info =
      CefBrowserInfoManager::GetInstance()->GetBrowserInfoForFrameTreeNode(
          frame_tree_node_id);
  if (info) {
    auto browser = info->browser();
    if (!browser) {
      LOG(WARNING) << "Found browser id " << info->browser_id()
                   << " but no browser object matching frame tree node id "
                   << frame_tree_node_id;
    }
    return browser;
  }

  return nullptr;
}

// static
CefRefPtr<CefBrowserHostBase> CefBrowserHostBase::GetBrowserForFrameRoute(
    int render_process_id,
    int render_routing_id) {
  if (render_process_id == -1 || render_routing_id == MSG_ROUTING_NONE)
    return nullptr;

  if (CEF_CURRENTLY_ON_UIT()) {
    // Use the non-thread-safe but potentially faster approach.
    content::RenderFrameHost* render_frame_host =
        content::RenderFrameHost::FromID(render_process_id, render_routing_id);
    if (!render_frame_host)
      return nullptr;
    return GetBrowserForHost(render_frame_host);
  } else {
    // Use the thread-safe approach.
    bool is_guest_view = false;
    auto info =
        CefBrowserInfoManager::GetInstance()->GetBrowserInfoForFrameRoute(
            render_process_id, render_routing_id, &is_guest_view);
    if (info && !is_guest_view) {
      auto browser = info->browser();
      if (!browser) {
        LOG(WARNING) << "Found browser id " << info->browser_id()
                     << " but no browser object matching frame process id "
                     << render_process_id << " and routing id "
                     << render_routing_id;
      }
      return browser;
    }
    return nullptr;
  }
}

CefBrowserHostBase::CefBrowserHostBase(
    const CefBrowserSettings& settings,
    CefRefPtr<CefClient> client,
    scoped_refptr<CefBrowserInfo> browser_info,
    CefRefPtr<CefRequestContextImpl> request_context)
    : settings_(settings),
      client_(client),
      browser_info_(browser_info),
      request_context_(request_context) {
  CEF_REQUIRE_UIT();
  DCHECK(!browser_info_->browser().get());
  browser_info_->SetBrowser(this);

  contents_delegate_ =
      std::make_unique<CefBrowserContentsDelegate>(browser_info_);
  contents_delegate_->AddObserver(this);
}

void CefBrowserHostBase::InitializeBrowser() {
  CEF_REQUIRE_UIT();

  // Associate the WebContents with this browser object.
  DCHECK(GetWebContents());
  WebContentsUserDataAdapter::Register(this);
}

void CefBrowserHostBase::DestroyBrowser() {
  CEF_REQUIRE_UIT();

  contents_delegate_->RemoveObserver(this);
  contents_delegate_->ObserveWebContents(nullptr);

  CefBrowserInfoManager::GetInstance()->RemoveBrowserInfo(browser_info_);
  browser_info_->SetBrowser(nullptr);
}

CefRefPtr<CefBrowser> CefBrowserHostBase::GetBrowser() {
  return this;
}

CefRefPtr<CefClient> CefBrowserHostBase::GetClient() {
  return client_;
}

CefRefPtr<CefRequestContext> CefBrowserHostBase::GetRequestContext() {
  return request_context_;
}

void CefBrowserHostBase::StartDownload(const CefString& url) {
  if (!CEF_CURRENTLY_ON_UIT()) {
    CEF_POST_TASK(
        CEF_UIT, base::BindOnce(&CefBrowserHostBase::StartDownload, this, url));
    return;
  }

  GURL gurl = GURL(url.ToString());
  if (gurl.is_empty() || !gurl.is_valid())
    return;

  auto web_contents = GetWebContents();
  if (!web_contents)
    return;

  auto browser_context = web_contents->GetBrowserContext();
  if (!browser_context)
    return;

  content::DownloadManager* manager =
      content::BrowserContext::GetDownloadManager(browser_context);
  if (!manager)
    return;

  std::unique_ptr<download::DownloadUrlParameters> params(
      content::DownloadRequestUtils::CreateDownloadForWebContentsMainFrame(
          web_contents, gurl, MISSING_TRAFFIC_ANNOTATION));
  manager->DownloadUrl(std::move(params));
}

void CefBrowserHostBase::DownloadImage(
    const CefString& image_url,
    bool is_favicon,
    uint32 max_image_size,
    bool bypass_cache,
    CefRefPtr<CefDownloadImageCallback> callback) {
  if (!CEF_CURRENTLY_ON_UIT()) {
    CEF_POST_TASK(
        CEF_UIT,
        base::BindOnce(&CefBrowserHostBase::DownloadImage, this, image_url,
                       is_favicon, max_image_size, bypass_cache, callback));
    return;
  }

  if (!callback)
    return;

  GURL gurl = GURL(image_url.ToString());
  if (gurl.is_empty() || !gurl.is_valid())
    return;

  auto web_contents = GetWebContents();
  if (!web_contents)
    return;

  web_contents->DownloadImage(
      gurl, is_favicon, max_image_size,
      max_image_size * gfx::ImageSkia::GetMaxSupportedScale(), bypass_cache,
      base::BindOnce(
          [](uint32 max_image_size,
             CefRefPtr<CefDownloadImageCallback> callback, int id,
             int http_status_code, const GURL& image_url,
             const std::vector<SkBitmap>& bitmaps,
             const std::vector<gfx::Size>& sizes) {
            CEF_REQUIRE_UIT();

            CefRefPtr<CefImageImpl> image_impl;

            if (!bitmaps.empty()) {
              image_impl = new CefImageImpl();
              image_impl->AddBitmaps(max_image_size, bitmaps);
            }

            callback->OnDownloadImageFinished(
                image_url.spec(), http_status_code, image_impl.get());
          },
          max_image_size, callback));
}

void CefBrowserHostBase::GetNavigationEntries(
    CefRefPtr<CefNavigationEntryVisitor> visitor,
    bool current_only) {
  DCHECK(visitor.get());
  if (!visitor.get())
    return;

  if (!CEF_CURRENTLY_ON_UIT()) {
    CEF_POST_TASK(
        CEF_UIT, base::BindOnce(&CefBrowserHostBase::GetNavigationEntries, this,
                                visitor, current_only));
    return;
  }

  auto web_contents = GetWebContents();
  if (!web_contents)
    return;

  content::NavigationController& controller = web_contents->GetController();
  const int total = controller.GetEntryCount();
  const int current = controller.GetCurrentEntryIndex();

  if (current_only) {
    // Visit only the current entry.
    CefRefPtr<CefNavigationEntryImpl> entry =
        new CefNavigationEntryImpl(controller.GetEntryAtIndex(current));
    visitor->Visit(entry.get(), true, current, total);
    entry->Detach(nullptr);
  } else {
    // Visit all entries.
    bool cont = true;
    for (int i = 0; i < total && cont; ++i) {
      CefRefPtr<CefNavigationEntryImpl> entry =
          new CefNavigationEntryImpl(controller.GetEntryAtIndex(i));
      cont = visitor->Visit(entry.get(), (i == current), i, total);
      entry->Detach(nullptr);
    }
  }
}

CefRefPtr<CefNavigationEntry> CefBrowserHostBase::GetVisibleNavigationEntry() {
  if (!CEF_CURRENTLY_ON_UIT()) {
    NOTREACHED() << "called on invalid thread";
    return nullptr;
  }

  content::NavigationEntry* entry = nullptr;
  auto web_contents = GetWebContents();
  if (web_contents)
    entry = web_contents->GetController().GetVisibleEntry();

  if (!entry)
    return nullptr;

  return new CefNavigationEntryImpl(entry);
}

void CefBrowserHostBase::ReplaceMisspelling(const CefString& word) {
  if (!CEF_CURRENTLY_ON_UIT()) {
    CEF_POST_TASK(
        CEF_UIT,
        base::BindOnce(&CefBrowserHostBase::ReplaceMisspelling, this, word));
    return;
  }

  auto web_contents = GetWebContents();
  if (web_contents)
    web_contents->ReplaceMisspelling(word);
}

void CefBrowserHostBase::AddWordToDictionary(const CefString& word) {
  if (!CEF_CURRENTLY_ON_UIT()) {
    CEF_POST_TASK(
        CEF_UIT,
        base::BindOnce(&CefBrowserHostBase::AddWordToDictionary, this, word));
    return;
  }

  auto web_contents = GetWebContents();
  if (!web_contents)
    return;

  SpellcheckService* spellcheck = nullptr;
  content::BrowserContext* browser_context = web_contents->GetBrowserContext();
  if (browser_context) {
    spellcheck = SpellcheckServiceFactory::GetForContext(browser_context);
    if (spellcheck)
      spellcheck->GetCustomDictionary()->AddWord(word);
  }
#if defined(OS_MAC)
  if (spellcheck && spellcheck::UseBrowserSpellChecker()) {
    spellcheck_platform::AddWord(spellcheck->platform_spell_checker(), word);
  }
#endif
}

CefRefPtr<CefBrowserHost> CefBrowserHostBase::GetHost() {
  return this;
}

bool CefBrowserHostBase::CanGoBack() {
  base::AutoLock lock_scope(state_lock_);
  return can_go_back_;
}

bool CefBrowserHostBase::CanGoForward() {
  base::AutoLock lock_scope(state_lock_);
  return can_go_forward_;
}

bool CefBrowserHostBase::IsLoading() {
  base::AutoLock lock_scope(state_lock_);
  return is_loading_;
}

int CefBrowserHostBase::GetIdentifier() {
  return browser_id();
}

bool CefBrowserHostBase::IsSame(CefRefPtr<CefBrowser> that) {
  auto impl = static_cast<CefBrowserHostBase*>(that.get());
  return (impl == this);
}

bool CefBrowserHostBase::HasDocument() {
  base::AutoLock lock_scope(state_lock_);
  return has_document_;
}

bool CefBrowserHostBase::IsPopup() {
  return browser_info_->is_popup();
}

CefRefPtr<CefFrame> CefBrowserHostBase::GetMainFrame() {
  return GetFrame(CefFrameHostImpl::kMainFrameId);
}

CefRefPtr<CefFrame> CefBrowserHostBase::GetFocusedFrame() {
  return GetFrame(CefFrameHostImpl::kFocusedFrameId);
}

CefRefPtr<CefFrame> CefBrowserHostBase::GetFrame(int64 identifier) {
  if (identifier == CefFrameHostImpl::kInvalidFrameId) {
    return nullptr;
  } else if (identifier == CefFrameHostImpl::kMainFrameId) {
    return browser_info_->GetMainFrame();
  } else if (identifier == CefFrameHostImpl::kFocusedFrameId) {
    base::AutoLock lock_scope(state_lock_);
    if (!focused_frame_) {
      // The main frame is focused by default.
      return browser_info_->GetMainFrame();
    }
    return focused_frame_;
  }

  return browser_info_->GetFrameForId(identifier);
}

CefRefPtr<CefFrame> CefBrowserHostBase::GetFrame(const CefString& name) {
  for (const auto& frame : browser_info_->GetAllFrames()) {
    if (frame->GetName() == name)
      return frame;
  }
  return nullptr;
}

size_t CefBrowserHostBase::GetFrameCount() {
  return browser_info_->GetAllFrames().size();
}

void CefBrowserHostBase::GetFrameIdentifiers(std::vector<int64>& identifiers) {
  if (identifiers.size() > 0)
    identifiers.clear();

  const auto frames = browser_info_->GetAllFrames();
  if (frames.empty())
    return;

  identifiers.reserve(frames.size());
  for (const auto& frame : frames) {
    identifiers.push_back(frame->GetIdentifier());
  }
}

void CefBrowserHostBase::GetFrameNames(std::vector<CefString>& names) {
  if (names.size() > 0)
    names.clear();

  const auto frames = browser_info_->GetAllFrames();
  if (frames.empty())
    return;

  names.reserve(frames.size());
  for (const auto& frame : frames) {
    names.push_back(frame->GetName());
  }
}

void CefBrowserHostBase::OnStateChanged(CefBrowserContentsState state_changed) {
  // Make sure that CefBrowser state is consistent before the associated
  // CefClient callback is executed.
  base::AutoLock lock_scope(state_lock_);
  if ((state_changed & CefBrowserContentsState::kNavigation) ==
      CefBrowserContentsState::kNavigation) {
    is_loading_ = contents_delegate_->is_loading();
    can_go_back_ = contents_delegate_->can_go_back();
    can_go_forward_ = contents_delegate_->can_go_forward();
  }
  if ((state_changed & CefBrowserContentsState::kDocument) ==
      CefBrowserContentsState::kDocument) {
    has_document_ = contents_delegate_->has_document();
  }
  if ((state_changed & CefBrowserContentsState::kFullscreen) ==
      CefBrowserContentsState::kFullscreen) {
    is_fullscreen_ = contents_delegate_->is_fullscreen();
  }
  if ((state_changed & CefBrowserContentsState::kFocusedFrame) ==
      CefBrowserContentsState::kFocusedFrame) {
    focused_frame_ = contents_delegate_->focused_frame();
  }
}

void CefBrowserHostBase::OnWebContentsDestroyed() {}

CefRefPtr<CefFrame> CefBrowserHostBase::GetFrameForHost(
    const content::RenderFrameHost* host) {
  CEF_REQUIRE_UIT();
  if (!host)
    return nullptr;

  return browser_info_->GetFrameForHost(host);
}

CefRefPtr<CefFrame> CefBrowserHostBase::GetFrameForFrameTreeNode(
    int frame_tree_node_id) {
  return browser_info_->GetFrameForFrameTreeNode(frame_tree_node_id, nullptr);
}

void CefBrowserHostBase::AddObserver(Observer* observer) {
  CEF_REQUIRE_UIT();
  observers_.AddObserver(observer);
}

void CefBrowserHostBase::RemoveObserver(Observer* observer) {
  CEF_REQUIRE_UIT();
  observers_.RemoveObserver(observer);
}

bool CefBrowserHostBase::HasObserver(Observer* observer) const {
  CEF_REQUIRE_UIT();
  return observers_.HasObserver(observer);
}

void CefBrowserHostBase::LoadMainFrameURL(const std::string& url,
                                          const content::Referrer& referrer,
                                          ui::PageTransition transition,
                                          const std::string& extra_headers) {
  auto callback = base::BindOnce(&CefBrowserHostBase::LoadMainFrameURL, this,
                                 url, referrer, transition, extra_headers);
  if (!CEF_CURRENTLY_ON_UIT()) {
    CEF_POST_TASK(CEF_UIT, std::move(callback));
    return;
  }

  if (browser_info_->IsNavigationLocked(std::move(callback))) {
    return;
  }

  auto web_contents = GetWebContents();
  if (web_contents) {
    GURL gurl = GURL(url);

    if (!gurl.is_valid() && !gurl.has_scheme()) {
      // Try to add "http://" at the beginning
      std::string new_url = std::string("http://") + url;
      gurl = GURL(new_url);
    }

    if (!gurl.is_valid()) {
      LOG(ERROR)
          << "Invalid URL passed to CefBrowserHostImpl::LoadMainFrameURL: "
          << url;
      return;
    }

    web_contents->GetController().LoadURL(gurl, referrer, transition,
                                          extra_headers);
    OnSetFocus(FOCUS_SOURCE_NAVIGATION);
  }
}

void CefBrowserHostBase::OnDidFinishLoad(CefRefPtr<CefFrameHostImpl> frame,
                                         const GURL& validated_url,
                                         int http_status_code) {
  frame->RefreshAttributes();

  // Give internal scheme handlers an opportunity to update content.
  scheme::DidFinishLoad(frame, validated_url);

  contents_delegate_->OnLoadEnd(frame, validated_url, http_status_code);
}

void CefBrowserHostBase::OnAfterCreated() {
  CEF_REQUIRE_UIT();
  if (client_) {
    if (auto handler = client_->GetLifeSpanHandler()) {
      handler->OnAfterCreated(this);
    }
  }
}

void CefBrowserHostBase::OnBeforeClose() {
  CEF_REQUIRE_UIT();
  if (client_) {
    if (auto handler = client_->GetLifeSpanHandler()) {
      handler->OnBeforeClose(this);
    }
  }
}

void CefBrowserHostBase::OnBrowserDestroyed() {
  CEF_REQUIRE_UIT();
  for (auto& observer : observers_)
    observer.OnBrowserDestroyed(this);
}

int CefBrowserHostBase::browser_id() const {
  return browser_info_->browser_id();
}

content::WebContents* CefBrowserHostBase::GetWebContents() const {
  CEF_REQUIRE_UIT();
  return contents_delegate_->web_contents();
}

content::BrowserContext* CefBrowserHostBase::GetBrowserContext() const {
  CEF_REQUIRE_UIT();
  auto web_contents = GetWebContents();
  if (web_contents)
    return web_contents->GetBrowserContext();
  return nullptr;
}
