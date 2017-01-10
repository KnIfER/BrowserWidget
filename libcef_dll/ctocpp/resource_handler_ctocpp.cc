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

#include "libcef_dll/cpptoc/callback_cpptoc.h"
#include "libcef_dll/cpptoc/request_cpptoc.h"
#include "libcef_dll/cpptoc/response_cpptoc.h"
#include "libcef_dll/ctocpp/resource_handler_ctocpp.h"


// VIRTUAL METHODS - Body may be edited by hand.

bool CefResourceHandlerCToCpp::ProcessRequest(CefRefPtr<CefRequest> request,
    CefRefPtr<CefCallback> callback) {
  cef_resource_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, process_request))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: request; type: refptr_diff
  DCHECK(request.get());
  if (!request.get())
    return false;
  // Verify param: callback; type: refptr_diff
  DCHECK(callback.get());
  if (!callback.get())
    return false;

  // Execute
  int _retval = _struct->process_request(_struct,
      CefRequestCppToC::Wrap(request),
      CefCallbackCppToC::Wrap(callback));

  // Return type: bool
  return _retval?true:false;
}

void CefResourceHandlerCToCpp::GetResponseHeaders(
    CefRefPtr<CefResponse> response, int64& response_length,
    CefString& redirectUrl) {
  cef_resource_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_response_headers))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: response; type: refptr_diff
  DCHECK(response.get());
  if (!response.get())
    return;

  // Execute
  _struct->get_response_headers(_struct,
      CefResponseCppToC::Wrap(response),
      &response_length,
      redirectUrl.GetWritableStruct());
}

bool CefResourceHandlerCToCpp::ReadResponse(void* data_out, int bytes_to_read,
    int& bytes_read, CefRefPtr<CefCallback> callback) {
  cef_resource_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, read_response))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: data_out; type: simple_byaddr
  DCHECK(data_out);
  if (!data_out)
    return false;
  // Verify param: callback; type: refptr_diff
  DCHECK(callback.get());
  if (!callback.get())
    return false;

  // Execute
  int _retval = _struct->read_response(_struct,
      data_out,
      bytes_to_read,
      &bytes_read,
      CefCallbackCppToC::Wrap(callback));

  // Return type: bool
  return _retval?true:false;
}

bool CefResourceHandlerCToCpp::CanGetCookie(const CefCookie& cookie) {
  cef_resource_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, can_get_cookie))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->can_get_cookie(_struct,
      &cookie);

  // Return type: bool
  return _retval?true:false;
}

bool CefResourceHandlerCToCpp::CanSetCookie(const CefCookie& cookie) {
  cef_resource_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, can_set_cookie))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->can_set_cookie(_struct,
      &cookie);

  // Return type: bool
  return _retval?true:false;
}

void CefResourceHandlerCToCpp::Cancel() {
  cef_resource_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, cancel))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->cancel(_struct);
}


// CONSTRUCTOR - Do not edit by hand.

CefResourceHandlerCToCpp::CefResourceHandlerCToCpp() {
}

template<> cef_resource_handler_t* CefCToCpp<CefResourceHandlerCToCpp,
    CefResourceHandler, cef_resource_handler_t>::UnwrapDerived(
    CefWrapperType type, CefResourceHandler* c) {
  NOTREACHED() << "Unexpected class type: " << type;
  return NULL;
}

#if DCHECK_IS_ON()
template<> base::AtomicRefCount CefCToCpp<CefResourceHandlerCToCpp,
    CefResourceHandler, cef_resource_handler_t>::DebugObjCt = 0;
#endif

template<> CefWrapperType CefCToCpp<CefResourceHandlerCToCpp,
    CefResourceHandler, cef_resource_handler_t>::kWrapperType =
    WT_RESOURCE_HANDLER;
