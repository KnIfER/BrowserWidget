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
// $hash=6ffdd140e2cb688f1d7db2eb1e2356a62ac08e5e$
//

#include "libcef_dll/ctocpp/media_sink_ctocpp.h"
#include "libcef_dll/ctocpp/media_source_ctocpp.h"
#include "libcef_dll/shutdown_checker.h"

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall") CefString CefMediaSinkCToCpp::GetId() {
  shutdown_checker::AssertNotShutdown();

  cef_media_sink_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_id))
    return CefString();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_string_userfree_t _retval = _struct->get_id(_struct);

  // Return type: string
  CefString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

NO_SANITIZE("cfi-icall") CefString CefMediaSinkCToCpp::GetName() {
  shutdown_checker::AssertNotShutdown();

  cef_media_sink_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_name))
    return CefString();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_string_userfree_t _retval = _struct->get_name(_struct);

  // Return type: string
  CefString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

NO_SANITIZE("cfi-icall") CefString CefMediaSinkCToCpp::GetDescription() {
  shutdown_checker::AssertNotShutdown();

  cef_media_sink_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_description))
    return CefString();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_string_userfree_t _retval = _struct->get_description(_struct);

  // Return type: string
  CefString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

NO_SANITIZE("cfi-icall")
CefMediaSink::IconType CefMediaSinkCToCpp::GetIconType() {
  shutdown_checker::AssertNotShutdown();

  cef_media_sink_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_icon_type))
    return CEF_MSIT_GENERIC;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_media_sink_icon_type_t _retval = _struct->get_icon_type(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") bool CefMediaSinkCToCpp::IsCastSink() {
  shutdown_checker::AssertNotShutdown();

  cef_media_sink_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, is_cast_sink))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_cast_sink(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") bool CefMediaSinkCToCpp::IsDialSink() {
  shutdown_checker::AssertNotShutdown();

  cef_media_sink_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, is_dial_sink))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_dial_sink(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefMediaSinkCToCpp::IsCompatibleWith(CefRefPtr<CefMediaSource> source) {
  shutdown_checker::AssertNotShutdown();

  cef_media_sink_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, is_compatible_with))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: source; type: refptr_same
  DCHECK(source.get());
  if (!source.get())
    return false;

  // Execute
  int _retval = _struct->is_compatible_with(
      _struct, CefMediaSourceCToCpp::Unwrap(source));

  // Return type: bool
  return _retval ? true : false;
}

// CONSTRUCTOR - Do not edit by hand.

CefMediaSinkCToCpp::CefMediaSinkCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

CefMediaSinkCToCpp::~CefMediaSinkCToCpp() {
  shutdown_checker::AssertNotShutdown();
}

template <>
cef_media_sink_t*
CefCToCppRefCounted<CefMediaSinkCToCpp, CefMediaSink, cef_media_sink_t>::
    UnwrapDerived(CefWrapperType type, CefMediaSink* c) {
  NOTREACHED() << "Unexpected class type: " << type;
  return nullptr;
}

template <>
CefWrapperType CefCToCppRefCounted<CefMediaSinkCToCpp,
                                   CefMediaSink,
                                   cef_media_sink_t>::kWrapperType =
    WT_MEDIA_SINK;
