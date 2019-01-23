// Copyright (c) 2019 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool. If making changes by
// hand only do so within the body of existing method and function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//
// $hash=350b86d1f5e2912141666328a21b2d4498424cca$
//

#include "libcef_dll/cpptoc/display_handler_cpptoc.h"
#include "libcef_dll/ctocpp/browser_ctocpp.h"
#include "libcef_dll/ctocpp/frame_ctocpp.h"
#include "libcef_dll/shutdown_checker.h"
#include "libcef_dll/transfer_util.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

void CEF_CALLBACK
display_handler_on_address_change(struct _cef_display_handler_t* self,
                                  cef_browser_t* browser,
                                  struct _cef_frame_t* frame,
                                  const cef_string_t* url) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return;
  // Verify param: frame; type: refptr_diff
  DCHECK(frame);
  if (!frame)
    return;
  // Verify param: url; type: string_byref_const
  DCHECK(url);
  if (!url)
    return;

  // Execute
  CefDisplayHandlerCppToC::Get(self)->OnAddressChange(
      CefBrowserCToCpp::Wrap(browser), CefFrameCToCpp::Wrap(frame),
      CefString(url));
}

void CEF_CALLBACK
display_handler_on_title_change(struct _cef_display_handler_t* self,
                                cef_browser_t* browser,
                                const cef_string_t* title) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return;
  // Unverified params: title

  // Execute
  CefDisplayHandlerCppToC::Get(self)->OnTitleChange(
      CefBrowserCToCpp::Wrap(browser), CefString(title));
}

void CEF_CALLBACK
display_handler_on_favicon_urlchange(struct _cef_display_handler_t* self,
                                     cef_browser_t* browser,
                                     cef_string_list_t icon_urls) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return;
  // Unverified params: icon_urls

  // Translate param: icon_urls; type: string_vec_byref_const
  std::vector<CefString> icon_urlsList;
  transfer_string_list_contents(icon_urls, icon_urlsList);

  // Execute
  CefDisplayHandlerCppToC::Get(self)->OnFaviconURLChange(
      CefBrowserCToCpp::Wrap(browser), icon_urlsList);
}

void CEF_CALLBACK
display_handler_on_fullscreen_mode_change(struct _cef_display_handler_t* self,
                                          cef_browser_t* browser,
                                          int fullscreen) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return;

  // Execute
  CefDisplayHandlerCppToC::Get(self)->OnFullscreenModeChange(
      CefBrowserCToCpp::Wrap(browser), fullscreen ? true : false);
}

int CEF_CALLBACK display_handler_on_tooltip(struct _cef_display_handler_t* self,
                                            cef_browser_t* browser,
                                            cef_string_t* text) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return 0;
  // Unverified params: text

  // Translate param: text; type: string_byref
  CefString textStr(text);

  // Execute
  bool _retval = CefDisplayHandlerCppToC::Get(self)->OnTooltip(
      CefBrowserCToCpp::Wrap(browser), textStr);

  // Return type: bool
  return _retval;
}

void CEF_CALLBACK
display_handler_on_status_message(struct _cef_display_handler_t* self,
                                  cef_browser_t* browser,
                                  const cef_string_t* value) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return;
  // Unverified params: value

  // Execute
  CefDisplayHandlerCppToC::Get(self)->OnStatusMessage(
      CefBrowserCToCpp::Wrap(browser), CefString(value));
}

int CEF_CALLBACK
display_handler_on_console_message(struct _cef_display_handler_t* self,
                                   cef_browser_t* browser,
                                   cef_log_severity_t level,
                                   const cef_string_t* message,
                                   const cef_string_t* source,
                                   int line) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return 0;
  // Unverified params: message, source

  // Execute
  bool _retval = CefDisplayHandlerCppToC::Get(self)->OnConsoleMessage(
      CefBrowserCToCpp::Wrap(browser), level, CefString(message),
      CefString(source), line);

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK
display_handler_on_auto_resize(struct _cef_display_handler_t* self,
                               cef_browser_t* browser,
                               const cef_size_t* new_size) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return 0;
  // Verify param: new_size; type: simple_byref_const
  DCHECK(new_size);
  if (!new_size)
    return 0;

  // Translate param: new_size; type: simple_byref_const
  CefSize new_sizeVal = new_size ? *new_size : CefSize();

  // Execute
  bool _retval = CefDisplayHandlerCppToC::Get(self)->OnAutoResize(
      CefBrowserCToCpp::Wrap(browser), new_sizeVal);

  // Return type: bool
  return _retval;
}

void CEF_CALLBACK
display_handler_on_loading_progress_change(struct _cef_display_handler_t* self,
                                           cef_browser_t* browser,
                                           double progress) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return;

  // Execute
  CefDisplayHandlerCppToC::Get(self)->OnLoadingProgressChange(
      CefBrowserCToCpp::Wrap(browser), progress);
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

CefDisplayHandlerCppToC::CefDisplayHandlerCppToC() {
  GetStruct()->on_address_change = display_handler_on_address_change;
  GetStruct()->on_title_change = display_handler_on_title_change;
  GetStruct()->on_favicon_urlchange = display_handler_on_favicon_urlchange;
  GetStruct()->on_fullscreen_mode_change =
      display_handler_on_fullscreen_mode_change;
  GetStruct()->on_tooltip = display_handler_on_tooltip;
  GetStruct()->on_status_message = display_handler_on_status_message;
  GetStruct()->on_console_message = display_handler_on_console_message;
  GetStruct()->on_auto_resize = display_handler_on_auto_resize;
  GetStruct()->on_loading_progress_change =
      display_handler_on_loading_progress_change;
}

// DESTRUCTOR - Do not edit by hand.

CefDisplayHandlerCppToC::~CefDisplayHandlerCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
CefRefPtr<CefDisplayHandler> CefCppToCRefCounted<
    CefDisplayHandlerCppToC,
    CefDisplayHandler,
    cef_display_handler_t>::UnwrapDerived(CefWrapperType type,
                                          cef_display_handler_t* s) {
  NOTREACHED() << "Unexpected class type: " << type;
  return NULL;
}

#if DCHECK_IS_ON()
template <>
base::AtomicRefCount CefCppToCRefCounted<CefDisplayHandlerCppToC,
                                         CefDisplayHandler,
                                         cef_display_handler_t>::DebugObjCt
    ATOMIC_DECLARATION;
#endif

template <>
CefWrapperType CefCppToCRefCounted<CefDisplayHandlerCppToC,
                                   CefDisplayHandler,
                                   cef_display_handler_t>::kWrapperType =
    WT_DISPLAY_HANDLER;
