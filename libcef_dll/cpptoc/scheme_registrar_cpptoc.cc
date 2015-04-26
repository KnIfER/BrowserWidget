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

#include "libcef_dll/cpptoc/scheme_registrar_cpptoc.h"


namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

int CEF_CALLBACK scheme_registrar_add_custom_scheme(
    struct _cef_scheme_registrar_t* self, const cef_string_t* scheme_name,
    int is_standard, int is_local, int is_display_isolated) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: scheme_name; type: string_byref_const
  DCHECK(scheme_name);
  if (!scheme_name)
    return 0;

  // Execute
  bool _retval = CefSchemeRegistrarCppToC::Get(self)->AddCustomScheme(
      CefString(scheme_name),
      is_standard?true:false,
      is_local?true:false,
      is_display_isolated?true:false);

  // Return type: bool
  return _retval;
}

}  // namespace


// CONSTRUCTOR - Do not edit by hand.

CefSchemeRegistrarCppToC::CefSchemeRegistrarCppToC() {
  GetStruct()->add_custom_scheme = scheme_registrar_add_custom_scheme;
}

template<> CefRefPtr<CefSchemeRegistrar> CefCppToC<CefSchemeRegistrarCppToC,
    CefSchemeRegistrar, cef_scheme_registrar_t>::UnwrapDerived(
    CefWrapperType type, cef_scheme_registrar_t* s) {
  NOTREACHED() << "Unexpected class type: " << type;
  return NULL;
}

#ifndef NDEBUG
template<> base::AtomicRefCount CefCppToC<CefSchemeRegistrarCppToC,
    CefSchemeRegistrar, cef_scheme_registrar_t>::DebugObjCt = 0;
#endif

template<> CefWrapperType CefCppToC<CefSchemeRegistrarCppToC,
    CefSchemeRegistrar, cef_scheme_registrar_t>::kWrapperType =
    WT_SCHEME_REGISTRAR;
