// Copyright (c) 2016 The Chromium Embedded Framework Authors. All rights
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

#include "libcef_dll/cpptoc/context_menu_handler_cpptoc.h"
#include "libcef_dll/ctocpp/browser_ctocpp.h"
#include "libcef_dll/ctocpp/context_menu_params_ctocpp.h"
#include "libcef_dll/ctocpp/frame_ctocpp.h"
#include "libcef_dll/ctocpp/menu_model_ctocpp.h"
#include "libcef_dll/ctocpp/run_context_menu_callback_ctocpp.h"


namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

void CEF_CALLBACK context_menu_handler_on_before_context_menu(
    struct _cef_context_menu_handler_t* self, cef_browser_t* browser,
    struct _cef_frame_t* frame, struct _cef_context_menu_params_t* params,
    struct _cef_menu_model_t* model) {
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
  // Verify param: params; type: refptr_diff
  DCHECK(params);
  if (!params)
    return;
  // Verify param: model; type: refptr_diff
  DCHECK(model);
  if (!model)
    return;

  // Execute
  CefContextMenuHandlerCppToC::Get(self)->OnBeforeContextMenu(
      CefBrowserCToCpp::Wrap(browser),
      CefFrameCToCpp::Wrap(frame),
      CefContextMenuParamsCToCpp::Wrap(params),
      CefMenuModelCToCpp::Wrap(model));
}

int CEF_CALLBACK context_menu_handler_run_context_menu(
    struct _cef_context_menu_handler_t* self, cef_browser_t* browser,
    struct _cef_frame_t* frame, struct _cef_context_menu_params_t* params,
    struct _cef_menu_model_t* model,
    cef_run_context_menu_callback_t* callback) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return 0;
  // Verify param: frame; type: refptr_diff
  DCHECK(frame);
  if (!frame)
    return 0;
  // Verify param: params; type: refptr_diff
  DCHECK(params);
  if (!params)
    return 0;
  // Verify param: model; type: refptr_diff
  DCHECK(model);
  if (!model)
    return 0;
  // Verify param: callback; type: refptr_diff
  DCHECK(callback);
  if (!callback)
    return 0;

  // Execute
  bool _retval = CefContextMenuHandlerCppToC::Get(self)->RunContextMenu(
      CefBrowserCToCpp::Wrap(browser),
      CefFrameCToCpp::Wrap(frame),
      CefContextMenuParamsCToCpp::Wrap(params),
      CefMenuModelCToCpp::Wrap(model),
      CefRunContextMenuCallbackCToCpp::Wrap(callback));

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK context_menu_handler_on_context_menu_command(
    struct _cef_context_menu_handler_t* self, cef_browser_t* browser,
    struct _cef_frame_t* frame, struct _cef_context_menu_params_t* params,
    int command_id, cef_event_flags_t event_flags) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return 0;
  // Verify param: frame; type: refptr_diff
  DCHECK(frame);
  if (!frame)
    return 0;
  // Verify param: params; type: refptr_diff
  DCHECK(params);
  if (!params)
    return 0;

  // Execute
  bool _retval = CefContextMenuHandlerCppToC::Get(self)->OnContextMenuCommand(
      CefBrowserCToCpp::Wrap(browser),
      CefFrameCToCpp::Wrap(frame),
      CefContextMenuParamsCToCpp::Wrap(params),
      command_id,
      event_flags);

  // Return type: bool
  return _retval;
}

void CEF_CALLBACK context_menu_handler_on_context_menu_dismissed(
    struct _cef_context_menu_handler_t* self, cef_browser_t* browser,
    struct _cef_frame_t* frame) {
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

  // Execute
  CefContextMenuHandlerCppToC::Get(self)->OnContextMenuDismissed(
      CefBrowserCToCpp::Wrap(browser),
      CefFrameCToCpp::Wrap(frame));
}

}  // namespace


// CONSTRUCTOR - Do not edit by hand.

CefContextMenuHandlerCppToC::CefContextMenuHandlerCppToC() {
  GetStruct()->on_before_context_menu =
      context_menu_handler_on_before_context_menu;
  GetStruct()->run_context_menu = context_menu_handler_run_context_menu;
  GetStruct()->on_context_menu_command =
      context_menu_handler_on_context_menu_command;
  GetStruct()->on_context_menu_dismissed =
      context_menu_handler_on_context_menu_dismissed;
}

template<> CefRefPtr<CefContextMenuHandler> CefCppToC<CefContextMenuHandlerCppToC,
    CefContextMenuHandler, cef_context_menu_handler_t>::UnwrapDerived(
    CefWrapperType type, cef_context_menu_handler_t* s) {
  NOTREACHED() << "Unexpected class type: " << type;
  return NULL;
}

#if DCHECK_IS_ON()
template<> base::AtomicRefCount CefCppToC<CefContextMenuHandlerCppToC,
    CefContextMenuHandler, cef_context_menu_handler_t>::DebugObjCt = 0;
#endif

template<> CefWrapperType CefCppToC<CefContextMenuHandlerCppToC,
    CefContextMenuHandler, cef_context_menu_handler_t>::kWrapperType =
    WT_CONTEXT_MENU_HANDLER;
