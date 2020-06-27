// Copyright (c) 2013 The Chromium Embedded Framework Authors.
// Portions (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "libcef/browser/chrome_browser_process_stub.h"

#include "libcef/browser/browser_context.h"
#include "libcef/browser/chrome_profile_manager_stub.h"
#include "libcef/browser/context.h"
#include "libcef/browser/prefs/browser_prefs.h"
#include "libcef/browser/thread_util.h"
#include "libcef/common/cef_switches.h"

#include "base/command_line.h"
#include "chrome/browser/net/system_network_context_manager.h"
#include "chrome/browser/policy/chrome_browser_policy_connector.h"
#include "chrome/browser/printing/background_printing_manager.h"
#include "chrome/browser/printing/print_job_manager.h"
#include "chrome/browser/printing/print_preview_dialog_controller.h"
#include "chrome/browser/ui/prefs/pref_watcher.h"
#include "components/net_log/chrome_net_log.h"
#include "components/prefs/pref_service.h"
#include "content/browser/startup_helper.h"
#include "content/public/common/content_switches.h"
#include "net/log/net_log_capture_mode.h"
#include "services/network/public/cpp/network_switches.h"
#include "services/network/public/cpp/shared_url_loader_factory.h"

ChromeBrowserProcessStub::ChromeBrowserProcessStub()
    : initialized_(false),
      context_initialized_(false),
      shutdown_(false),
      locale_("en-US") {}

ChromeBrowserProcessStub::~ChromeBrowserProcessStub() {
  DCHECK((!initialized_ && !context_initialized_) || shutdown_);
}

void ChromeBrowserProcessStub::Initialize() {
  DCHECK(!initialized_);
  DCHECK(!context_initialized_);
  DCHECK(!shutdown_);
  DCHECK(!field_trial_list_);

  // Initialize this early before any code tries to check feature flags.
  field_trial_list_ = content::SetUpFieldTrialsAndFeatureList();

  initialized_ = true;
}

void ChromeBrowserProcessStub::OnContextInitialized() {
  CEF_REQUIRE_UIT();
  DCHECK(initialized_);
  DCHECK(!context_initialized_);
  DCHECK(!shutdown_);

  // Must be created after the NotificationService.
  print_job_manager_.reset(new printing::PrintJobManager());
  profile_manager_.reset(new ChromeProfileManagerStub());
  event_router_forwarder_ = new extensions::EventRouterForwarder();
  context_initialized_ = true;
}

void ChromeBrowserProcessStub::CleanupOnUIThread() {
  CEF_REQUIRE_UIT();
  DCHECK(initialized_);
  DCHECK(context_initialized_);
  DCHECK(!shutdown_);

  // Wait for the pending print jobs to finish. Don't do this later, since
  // this might cause a nested message loop to run, and we don't want pending
  // tasks to run once teardown has started.
  print_job_manager_->Shutdown();
  print_job_manager_.reset(nullptr);
  print_preview_dialog_controller_ = nullptr;

  profile_manager_.reset();
  event_router_forwarder_ = nullptr;

  if (SystemNetworkContextManager::GetInstance()) {
    SystemNetworkContextManager::DeleteInstance();
  }

  // Release any references held by objects associated with a Profile. The
  // Profile will be deleted later.
  for (const auto& profile : CefBrowserContext::GetAll()) {
    // Release any references to |local_state_|.
    PrefWatcher* pref_watcher = PrefWatcher::Get(profile);
    if (pref_watcher)
      pref_watcher->Shutdown();

    // Unregister observers for |background_printing_manager_|.
    if (background_printing_manager_) {
      background_printing_manager_->DeletePreviewContentsForBrowserContext(
          profile);
    }
  }

  local_state_.reset();
  browser_policy_connector_.reset();

  background_printing_manager_.reset();

  field_trial_list_.reset();

  shutdown_ = true;
}

void ChromeBrowserProcessStub::EndSession() {
  NOTREACHED();
}

void ChromeBrowserProcessStub::FlushLocalStateAndReply(
    base::OnceClosure reply) {
  NOTREACHED();
}

metrics_services_manager::MetricsServicesManager*
ChromeBrowserProcessStub::GetMetricsServicesManager() {
  NOTREACHED();
  return nullptr;
}

metrics::MetricsService* ChromeBrowserProcessStub::metrics_service() {
  NOTREACHED();
  return nullptr;
}

rappor::RapporServiceImpl* ChromeBrowserProcessStub::rappor_service() {
  // Called from PluginInfoHostImpl::ReportMetrics.
  return nullptr;
}

SystemNetworkContextManager*
ChromeBrowserProcessStub::system_network_context_manager() {
  DCHECK(SystemNetworkContextManager::GetInstance());
  return SystemNetworkContextManager::GetInstance();
}

network::NetworkQualityTracker*
ChromeBrowserProcessStub::network_quality_tracker() {
  NOTREACHED();
  return nullptr;
}

WatchDogThread* ChromeBrowserProcessStub::watchdog_thread() {
  NOTREACHED();
  return nullptr;
}

ProfileManager* ChromeBrowserProcessStub::profile_manager() {
  DCHECK(context_initialized_);
  return profile_manager_.get();
}

PrefService* ChromeBrowserProcessStub::local_state() {
  DCHECK(initialized_);
  if (!local_state_) {
    // Use a location that is shared by all request contexts.
    const CefSettings& settings = CefContext::Get()->settings();
    const base::FilePath& root_cache_path =
        base::FilePath(CefString(&settings.root_cache_path));

    // Used for very early NetworkService initialization.
    // Always persist preferences for this PrefService if possible because it
    // contains the cookie encryption key on Windows.
    local_state_ =
        browser_prefs::CreatePrefService(nullptr /* profile */, root_cache_path,
                                         true /* persist_user_preferences */);
  }
  return local_state_.get();
}

scoped_refptr<network::SharedURLLoaderFactory>
ChromeBrowserProcessStub::shared_url_loader_factory() {
  NOTREACHED();
  return nullptr;
}

variations::VariationsService* ChromeBrowserProcessStub::variations_service() {
  NOTREACHED();
  return nullptr;
}

BrowserProcessPlatformPart* ChromeBrowserProcessStub::platform_part() {
  NOTREACHED();
  return nullptr;
}

extensions::EventRouterForwarder*
ChromeBrowserProcessStub::extension_event_router_forwarder() {
  DCHECK(context_initialized_);
  return event_router_forwarder_.get();
}

NotificationUIManager* ChromeBrowserProcessStub::notification_ui_manager() {
  NOTREACHED();
  return nullptr;
}

NotificationPlatformBridge*
ChromeBrowserProcessStub::notification_platform_bridge() {
  NOTREACHED();
  return nullptr;
}

policy::ChromeBrowserPolicyConnector*
ChromeBrowserProcessStub::browser_policy_connector() {
  if (!browser_policy_connector_) {
    browser_policy_connector_ =
        std::make_unique<policy::ChromeBrowserPolicyConnector>();
  }
  return browser_policy_connector_.get();
}

policy::PolicyService* ChromeBrowserProcessStub::policy_service() {
  return browser_policy_connector()->GetPolicyService();
}

IconManager* ChromeBrowserProcessStub::icon_manager() {
  NOTREACHED();
  return nullptr;
}

GpuModeManager* ChromeBrowserProcessStub::gpu_mode_manager() {
  NOTREACHED();
  return nullptr;
}

void ChromeBrowserProcessStub::CreateDevToolsProtocolHandler() {
  NOTREACHED();
}

void ChromeBrowserProcessStub::CreateDevToolsAutoOpener() {
  NOTREACHED();
}

bool ChromeBrowserProcessStub::IsShuttingDown() {
  NOTREACHED();
  return false;
}

printing::PrintJobManager* ChromeBrowserProcessStub::print_job_manager() {
  DCHECK(context_initialized_);
  return print_job_manager_.get();
}

printing::PrintPreviewDialogController*
ChromeBrowserProcessStub::print_preview_dialog_controller() {
  if (!print_preview_dialog_controller_.get()) {
    print_preview_dialog_controller_ =
        new printing::PrintPreviewDialogController();
  }
  return print_preview_dialog_controller_.get();
}

printing::BackgroundPrintingManager*
ChromeBrowserProcessStub::background_printing_manager() {
  if (!background_printing_manager_.get()) {
    background_printing_manager_.reset(
        new printing::BackgroundPrintingManager());
  }
  return background_printing_manager_.get();
}

IntranetRedirectDetector*
ChromeBrowserProcessStub::intranet_redirect_detector() {
  NOTREACHED();
  return nullptr;
}

const std::string& ChromeBrowserProcessStub::GetApplicationLocale() {
  DCHECK(!locale_.empty());
  return locale_;
}

void ChromeBrowserProcessStub::SetApplicationLocale(const std::string& locale) {
  locale_ = locale;
}

DownloadStatusUpdater* ChromeBrowserProcessStub::download_status_updater() {
  NOTREACHED();
  return nullptr;
}

DownloadRequestLimiter* ChromeBrowserProcessStub::download_request_limiter() {
  NOTREACHED();
  return nullptr;
}

#if BUILDFLAG(ENABLE_BACKGROUND_MODE)
BackgroundModeManager* ChromeBrowserProcessStub::background_mode_manager() {
  NOTREACHED();
  return nullptr;
}

void ChromeBrowserProcessStub::set_background_mode_manager_for_test(
    std::unique_ptr<BackgroundModeManager> manager) {
  NOTREACHED();
}
#endif

StatusTray* ChromeBrowserProcessStub::status_tray() {
  NOTREACHED();
  return nullptr;
}

safe_browsing::SafeBrowsingService*
ChromeBrowserProcessStub::safe_browsing_service() {
  return nullptr;
}

subresource_filter::RulesetService*
ChromeBrowserProcessStub::subresource_filter_ruleset_service() {
  NOTREACHED();
  return nullptr;
}

optimization_guide::OptimizationGuideService*
ChromeBrowserProcessStub::optimization_guide_service() {
  NOTREACHED();
  return nullptr;
}

StartupData* ChromeBrowserProcessStub::startup_data() {
  NOTREACHED();
  return nullptr;
}

#if (defined(OS_WIN) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
void ChromeBrowserProcessStub::StartAutoupdateTimer() {}
#endif

component_updater::ComponentUpdateService*
ChromeBrowserProcessStub::component_updater() {
  NOTREACHED();
  return nullptr;
}

MediaFileSystemRegistry*
ChromeBrowserProcessStub::media_file_system_registry() {
  NOTREACHED();
  return nullptr;
}

WebRtcLogUploader* ChromeBrowserProcessStub::webrtc_log_uploader() {
  NOTREACHED();
  return nullptr;
}

network_time::NetworkTimeTracker*
ChromeBrowserProcessStub::network_time_tracker() {
  NOTREACHED();
  return nullptr;
}

gcm::GCMDriver* ChromeBrowserProcessStub::gcm_driver() {
  NOTREACHED();
  return nullptr;
}

resource_coordinator::TabManager* ChromeBrowserProcessStub::GetTabManager() {
  NOTREACHED();
  return nullptr;
}

resource_coordinator::ResourceCoordinatorParts*
ChromeBrowserProcessStub::resource_coordinator_parts() {
  NOTREACHED();
  return nullptr;
}

BuildState* ChromeBrowserProcessStub::GetBuildState() {
  NOTREACHED();
  return nullptr;
}
