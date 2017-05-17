// Copyright (c) 2017 The Chromium Embedded Framework Authors. All rights
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
// $hash=05be760ce7d3e0aaba329f7cfe3b83b7d6b94699$
//

#include "libcef_dll/cpptoc/jsdialog_callback_cpptoc.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

void CEF_CALLBACK jsdialog_callback_cont(struct _cef_jsdialog_callback_t* self,
                                         int success,
                                         const cef_string_t* user_input) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Unverified params: user_input

  // Execute
  CefJSDialogCallbackCppToC::Get(self)->Continue(success ? true : false,
                                                 CefString(user_input));
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

CefJSDialogCallbackCppToC::CefJSDialogCallbackCppToC() {
  GetStruct()->cont = jsdialog_callback_cont;
}

template <>
CefRefPtr<CefJSDialogCallback> CefCppToCRefCounted<
    CefJSDialogCallbackCppToC,
    CefJSDialogCallback,
    cef_jsdialog_callback_t>::UnwrapDerived(CefWrapperType type,
                                            cef_jsdialog_callback_t* s) {
  NOTREACHED() << "Unexpected class type: " << type;
  return NULL;
}

#if DCHECK_IS_ON()
template <>
base::AtomicRefCount CefCppToCRefCounted<CefJSDialogCallbackCppToC,
                                         CefJSDialogCallback,
                                         cef_jsdialog_callback_t>::DebugObjCt =
    0;
#endif

template <>
CefWrapperType CefCppToCRefCounted<CefJSDialogCallbackCppToC,
                                   CefJSDialogCallback,
                                   cef_jsdialog_callback_t>::kWrapperType =
    WT_JSDIALOG_CALLBACK;
