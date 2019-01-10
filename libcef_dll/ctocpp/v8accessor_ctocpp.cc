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
// $hash=beae419588b1c5068e503301940230556491987c$
//

#include "libcef_dll/ctocpp/v8accessor_ctocpp.h"
#include "libcef_dll/cpptoc/v8value_cpptoc.h"

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
bool CefV8AccessorCToCpp::Get(const CefString& name,
                              const CefRefPtr<CefV8Value> object,
                              CefRefPtr<CefV8Value>& retval,
                              CefString& exception) {
  cef_v8accessor_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: name; type: string_byref_const
  DCHECK(!name.empty());
  if (name.empty())
    return false;
  // Verify param: object; type: refptr_diff
  DCHECK(object.get());
  if (!object.get())
    return false;

  // Translate param: retval; type: refptr_diff_byref
  cef_v8value_t* retvalStruct = NULL;
  if (retval.get())
    retvalStruct = CefV8ValueCppToC::Wrap(retval);
  cef_v8value_t* retvalOrig = retvalStruct;

  // Execute
  int _retval =
      _struct->get(_struct, name.GetStruct(), CefV8ValueCppToC::Wrap(object),
                   &retvalStruct, exception.GetWritableStruct());

  // Restore param:retval; type: refptr_diff_byref
  if (retvalStruct) {
    if (retvalStruct != retvalOrig) {
      retval = CefV8ValueCppToC::Unwrap(retvalStruct);
    }
  } else {
    retval = NULL;
  }

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefV8AccessorCToCpp::Set(const CefString& name,
                              const CefRefPtr<CefV8Value> object,
                              const CefRefPtr<CefV8Value> value,
                              CefString& exception) {
  cef_v8accessor_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, set))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: name; type: string_byref_const
  DCHECK(!name.empty());
  if (name.empty())
    return false;
  // Verify param: object; type: refptr_diff
  DCHECK(object.get());
  if (!object.get())
    return false;
  // Verify param: value; type: refptr_diff
  DCHECK(value.get());
  if (!value.get())
    return false;

  // Execute
  int _retval = _struct->set(
      _struct, name.GetStruct(), CefV8ValueCppToC::Wrap(object),
      CefV8ValueCppToC::Wrap(value), exception.GetWritableStruct());

  // Return type: bool
  return _retval ? true : false;
}

// CONSTRUCTOR - Do not edit by hand.

CefV8AccessorCToCpp::CefV8AccessorCToCpp() {}

template <>
cef_v8accessor_t*
CefCToCppRefCounted<CefV8AccessorCToCpp, CefV8Accessor, cef_v8accessor_t>::
    UnwrapDerived(CefWrapperType type, CefV8Accessor* c) {
  NOTREACHED() << "Unexpected class type: " << type;
  return NULL;
}

#if DCHECK_IS_ON()
template <>
base::AtomicRefCount
    CefCToCppRefCounted<CefV8AccessorCToCpp, CefV8Accessor, cef_v8accessor_t>::
        DebugObjCt ATOMIC_DECLARATION;
#endif

template <>
CefWrapperType CefCToCppRefCounted<CefV8AccessorCToCpp,
                                   CefV8Accessor,
                                   cef_v8accessor_t>::kWrapperType =
    WT_V8ACCESSOR;
