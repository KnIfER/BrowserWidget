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
// $hash=0191a03a4fde402c6c3949f8f8b86e7066ff0308$
//

#include "libcef_dll/ctocpp/accessibility_handler_ctocpp.h"
#include "libcef_dll/cpptoc/value_cpptoc.h"

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
void CefAccessibilityHandlerCToCpp::OnAccessibilityTreeChange(
    CefRefPtr<CefValue> value) {
  cef_accessibility_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, on_accessibility_tree_change))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: value; type: refptr_diff
  DCHECK(value.get());
  if (!value.get())
    return;

  // Execute
  _struct->on_accessibility_tree_change(_struct, CefValueCppToC::Wrap(value));
}

NO_SANITIZE("cfi-icall")
void CefAccessibilityHandlerCToCpp::OnAccessibilityLocationChange(
    CefRefPtr<CefValue> value) {
  cef_accessibility_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, on_accessibility_location_change))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: value; type: refptr_diff
  DCHECK(value.get());
  if (!value.get())
    return;

  // Execute
  _struct->on_accessibility_location_change(_struct,
                                            CefValueCppToC::Wrap(value));
}

// CONSTRUCTOR - Do not edit by hand.

CefAccessibilityHandlerCToCpp::CefAccessibilityHandlerCToCpp() {}

template <>
cef_accessibility_handler_t* CefCToCppRefCounted<
    CefAccessibilityHandlerCToCpp,
    CefAccessibilityHandler,
    cef_accessibility_handler_t>::UnwrapDerived(CefWrapperType type,
                                                CefAccessibilityHandler* c) {
  NOTREACHED() << "Unexpected class type: " << type;
  return NULL;
}

#if DCHECK_IS_ON()
template <>
base::AtomicRefCount CefCToCppRefCounted<
    CefAccessibilityHandlerCToCpp,
    CefAccessibilityHandler,
    cef_accessibility_handler_t>::DebugObjCt ATOMIC_DECLARATION;
#endif

template <>
CefWrapperType CefCToCppRefCounted<CefAccessibilityHandlerCToCpp,
                                   CefAccessibilityHandler,
                                   cef_accessibility_handler_t>::kWrapperType =
    WT_ACCESSIBILITY_HANDLER;
