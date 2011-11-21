// Copyright (c) 2011 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// A portion of this file was generated by the CEF translator tool.  When
// making changes by hand only do so within the body of existing static and
// virtual method implementations. See the translator.README.txt file in the
// tools directory for more information.
//

#include "libcef_dll/cpptoc/browser_cpptoc.h"
#include "libcef_dll/cpptoc/frame_cpptoc.h"
#include "libcef_dll/cpptoc/v8context_cpptoc.h"
#include "libcef_dll/ctocpp/v8context_handler_ctocpp.h"


// VIRTUAL METHODS - Body may be edited by hand.

void CefV8ContextHandlerCToCpp::OnContextCreated(CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame, CefRefPtr<CefV8Context> context)
{
  if (CEF_MEMBER_MISSING(struct_, on_context_created))
    return;

  struct_->on_context_created(struct_, CefBrowserCppToC::Wrap(browser),
      CefFrameCppToC::Wrap(frame), CefV8ContextCppToC::Wrap(context));
}

void CefV8ContextHandlerCToCpp::OnContextReleased(CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame, CefRefPtr<CefV8Context> context)
{
  if (CEF_MEMBER_MISSING(struct_, on_context_released))
    return;

  struct_->on_context_released(struct_, CefBrowserCppToC::Wrap(browser),
      CefFrameCppToC::Wrap(frame), CefV8ContextCppToC::Wrap(context));
}


#ifndef NDEBUG
template<> long CefCToCpp<CefV8ContextHandlerCToCpp, CefV8ContextHandler,
    cef_v8context_handler_t>::DebugObjCt = 0;
#endif

