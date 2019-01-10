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
// $hash=a1ff97873ff99c6b200a1f497bce56dede1b3c29$
//

#include "libcef_dll/ctocpp/web_plugin_unstable_callback_ctocpp.h"

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
void CefWebPluginUnstableCallbackCToCpp::IsUnstable(const CefString& path,
                                                    bool unstable) {
  cef_web_plugin_unstable_callback_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, is_unstable))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: path; type: string_byref_const
  DCHECK(!path.empty());
  if (path.empty())
    return;

  // Execute
  _struct->is_unstable(_struct, path.GetStruct(), unstable);
}

// CONSTRUCTOR - Do not edit by hand.

CefWebPluginUnstableCallbackCToCpp::CefWebPluginUnstableCallbackCToCpp() {}

template <>
cef_web_plugin_unstable_callback_t*
CefCToCppRefCounted<CefWebPluginUnstableCallbackCToCpp,
                    CefWebPluginUnstableCallback,
                    cef_web_plugin_unstable_callback_t>::
    UnwrapDerived(CefWrapperType type, CefWebPluginUnstableCallback* c) {
  NOTREACHED() << "Unexpected class type: " << type;
  return NULL;
}

#if DCHECK_IS_ON()
template <>
base::AtomicRefCount CefCToCppRefCounted<
    CefWebPluginUnstableCallbackCToCpp,
    CefWebPluginUnstableCallback,
    cef_web_plugin_unstable_callback_t>::DebugObjCt ATOMIC_DECLARATION;
#endif

template <>
CefWrapperType
    CefCToCppRefCounted<CefWebPluginUnstableCallbackCToCpp,
                        CefWebPluginUnstableCallback,
                        cef_web_plugin_unstable_callback_t>::kWrapperType =
        WT_WEB_PLUGIN_UNSTABLE_CALLBACK;
