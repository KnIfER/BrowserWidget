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
// $hash=96938638213bc6f72dba268295fd175b90ff3d2e$
//

#include "libcef_dll/cpptoc/web_plugin_info_cpptoc.h"
#include "libcef_dll/shutdown_checker.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

cef_string_userfree_t CEF_CALLBACK
web_plugin_info_get_name(struct _cef_web_plugin_info_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefWebPluginInfoCppToC::Get(self)->GetName();

  // Return type: string
  return _retval.DetachToUserFree();
}

cef_string_userfree_t CEF_CALLBACK
web_plugin_info_get_path(struct _cef_web_plugin_info_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefWebPluginInfoCppToC::Get(self)->GetPath();

  // Return type: string
  return _retval.DetachToUserFree();
}

cef_string_userfree_t CEF_CALLBACK
web_plugin_info_get_version(struct _cef_web_plugin_info_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefWebPluginInfoCppToC::Get(self)->GetVersion();

  // Return type: string
  return _retval.DetachToUserFree();
}

cef_string_userfree_t CEF_CALLBACK
web_plugin_info_get_description(struct _cef_web_plugin_info_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefWebPluginInfoCppToC::Get(self)->GetDescription();

  // Return type: string
  return _retval.DetachToUserFree();
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

CefWebPluginInfoCppToC::CefWebPluginInfoCppToC() {
  GetStruct()->get_name = web_plugin_info_get_name;
  GetStruct()->get_path = web_plugin_info_get_path;
  GetStruct()->get_version = web_plugin_info_get_version;
  GetStruct()->get_description = web_plugin_info_get_description;
}

// DESTRUCTOR - Do not edit by hand.

CefWebPluginInfoCppToC::~CefWebPluginInfoCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
CefRefPtr<CefWebPluginInfo> CefCppToCRefCounted<
    CefWebPluginInfoCppToC,
    CefWebPluginInfo,
    cef_web_plugin_info_t>::UnwrapDerived(CefWrapperType type,
                                          cef_web_plugin_info_t* s) {
  NOTREACHED() << "Unexpected class type: " << type;
  return NULL;
}

#if DCHECK_IS_ON()
template <>
base::AtomicRefCount CefCppToCRefCounted<CefWebPluginInfoCppToC,
                                         CefWebPluginInfo,
                                         cef_web_plugin_info_t>::DebugObjCt
    ATOMIC_DECLARATION;
#endif

template <>
CefWrapperType CefCppToCRefCounted<CefWebPluginInfoCppToC,
                                   CefWebPluginInfo,
                                   cef_web_plugin_info_t>::kWrapperType =
    WT_WEB_PLUGIN_INFO;
