// Copyright (c) 2015 The Chromium Embedded Framework Authors. All rights
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

#include "libcef_dll/cpptoc/browser_cpptoc.h"
#include "libcef_dll/cpptoc/frame_cpptoc.h"
#include "libcef_dll/ctocpp/display_handler_ctocpp.h"


// VIRTUAL METHODS - Body may be edited by hand.

void CefDisplayHandlerCToCpp::OnAddressChange(CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame, const CefString& url) {
  if (CEF_MEMBER_MISSING(struct_, on_address_change))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return;
  // Verify param: frame; type: refptr_diff
  DCHECK(frame.get());
  if (!frame.get())
    return;
  // Verify param: url; type: string_byref_const
  DCHECK(!url.empty());
  if (url.empty())
    return;

  // Execute
  struct_->on_address_change(struct_,
      CefBrowserCppToC::Wrap(browser),
      CefFrameCppToC::Wrap(frame),
      url.GetStruct());
}

void CefDisplayHandlerCToCpp::OnTitleChange(CefRefPtr<CefBrowser> browser,
    const CefString& title) {
  if (CEF_MEMBER_MISSING(struct_, on_title_change))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return;
  // Unverified params: title

  // Execute
  struct_->on_title_change(struct_,
      CefBrowserCppToC::Wrap(browser),
      title.GetStruct());
}

bool CefDisplayHandlerCToCpp::OnTooltip(CefRefPtr<CefBrowser> browser,
    CefString& text) {
  if (CEF_MEMBER_MISSING(struct_, on_tooltip))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return false;
  // Unverified params: text

  // Execute
  int _retval = struct_->on_tooltip(struct_,
      CefBrowserCppToC::Wrap(browser),
      text.GetWritableStruct());

  // Return type: bool
  return _retval?true:false;
}

void CefDisplayHandlerCToCpp::OnStatusMessage(CefRefPtr<CefBrowser> browser,
    const CefString& value) {
  if (CEF_MEMBER_MISSING(struct_, on_status_message))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return;
  // Unverified params: value

  // Execute
  struct_->on_status_message(struct_,
      CefBrowserCppToC::Wrap(browser),
      value.GetStruct());
}

bool CefDisplayHandlerCToCpp::OnConsoleMessage(CefRefPtr<CefBrowser> browser,
    const CefString& message, const CefString& source, int line) {
  if (CEF_MEMBER_MISSING(struct_, on_console_message))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return false;
  // Unverified params: message, source

  // Execute
  int _retval = struct_->on_console_message(struct_,
      CefBrowserCppToC::Wrap(browser),
      message.GetStruct(),
      source.GetStruct(),
      line);

  // Return type: bool
  return _retval?true:false;
}


#ifndef NDEBUG
template<> base::AtomicRefCount CefCToCpp<CefDisplayHandlerCToCpp,
    CefDisplayHandler, cef_display_handler_t>::DebugObjCt = 0;
#endif

