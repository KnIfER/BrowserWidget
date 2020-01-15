// Copyright (c) 2020 The Chromium Embedded Framework Authors. All rights
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
// $hash=d0eec19bee7cbc38c676ef6ca936483cc93bb7fc$
//

#include "libcef_dll/ctocpp/context_menu_handler_ctocpp.h"
#include "libcef_dll/cpptoc/browser_cpptoc.h"
#include "libcef_dll/cpptoc/context_menu_params_cpptoc.h"
#include "libcef_dll/cpptoc/frame_cpptoc.h"
#include "libcef_dll/cpptoc/menu_model_cpptoc.h"
#include "libcef_dll/cpptoc/run_context_menu_callback_cpptoc.h"
#include "libcef_dll/shutdown_checker.h"

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
void CefContextMenuHandlerCToCpp::OnBeforeContextMenu(
    CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    CefRefPtr<CefContextMenuParams> params,
    CefRefPtr<CefMenuModel> model) {
  shutdown_checker::AssertNotShutdown();

  cef_context_menu_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, on_before_context_menu))
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
  // Verify param: params; type: refptr_diff
  DCHECK(params.get());
  if (!params.get())
    return;
  // Verify param: model; type: refptr_diff
  DCHECK(model.get());
  if (!model.get())
    return;

  // Execute
  _struct->on_before_context_menu(_struct, CefBrowserCppToC::Wrap(browser),
                                  CefFrameCppToC::Wrap(frame),
                                  CefContextMenuParamsCppToC::Wrap(params),
                                  CefMenuModelCppToC::Wrap(model));
}

NO_SANITIZE("cfi-icall")
bool CefContextMenuHandlerCToCpp::RunContextMenu(
    CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    CefRefPtr<CefContextMenuParams> params,
    CefRefPtr<CefMenuModel> model,
    CefRefPtr<CefRunContextMenuCallback> callback) {
  shutdown_checker::AssertNotShutdown();

  cef_context_menu_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, run_context_menu))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return false;
  // Verify param: frame; type: refptr_diff
  DCHECK(frame.get());
  if (!frame.get())
    return false;
  // Verify param: params; type: refptr_diff
  DCHECK(params.get());
  if (!params.get())
    return false;
  // Verify param: model; type: refptr_diff
  DCHECK(model.get());
  if (!model.get())
    return false;
  // Verify param: callback; type: refptr_diff
  DCHECK(callback.get());
  if (!callback.get())
    return false;

  // Execute
  int _retval = _struct->run_context_menu(
      _struct, CefBrowserCppToC::Wrap(browser), CefFrameCppToC::Wrap(frame),
      CefContextMenuParamsCppToC::Wrap(params), CefMenuModelCppToC::Wrap(model),
      CefRunContextMenuCallbackCppToC::Wrap(callback));

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefContextMenuHandlerCToCpp::OnContextMenuCommand(
    CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    CefRefPtr<CefContextMenuParams> params,
    int command_id,
    EventFlags event_flags) {
  shutdown_checker::AssertNotShutdown();

  cef_context_menu_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, on_context_menu_command))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return false;
  // Verify param: frame; type: refptr_diff
  DCHECK(frame.get());
  if (!frame.get())
    return false;
  // Verify param: params; type: refptr_diff
  DCHECK(params.get());
  if (!params.get())
    return false;

  // Execute
  int _retval = _struct->on_context_menu_command(
      _struct, CefBrowserCppToC::Wrap(browser), CefFrameCppToC::Wrap(frame),
      CefContextMenuParamsCppToC::Wrap(params), command_id, event_flags);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
void CefContextMenuHandlerCToCpp::OnContextMenuDismissed(
    CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame) {
  shutdown_checker::AssertNotShutdown();

  cef_context_menu_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, on_context_menu_dismissed))
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

  // Execute
  _struct->on_context_menu_dismissed(_struct, CefBrowserCppToC::Wrap(browser),
                                     CefFrameCppToC::Wrap(frame));
}

// CONSTRUCTOR - Do not edit by hand.

CefContextMenuHandlerCToCpp::CefContextMenuHandlerCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

CefContextMenuHandlerCToCpp::~CefContextMenuHandlerCToCpp() {
  shutdown_checker::AssertNotShutdown();
}

template <>
cef_context_menu_handler_t* CefCToCppRefCounted<
    CefContextMenuHandlerCToCpp,
    CefContextMenuHandler,
    cef_context_menu_handler_t>::UnwrapDerived(CefWrapperType type,
                                               CefContextMenuHandler* c) {
  NOTREACHED() << "Unexpected class type: " << type;
  return nullptr;
}

template <>
CefWrapperType CefCToCppRefCounted<CefContextMenuHandlerCToCpp,
                                   CefContextMenuHandler,
                                   cef_context_menu_handler_t>::kWrapperType =
    WT_CONTEXT_MENU_HANDLER;
