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
// $hash=015081f57475317bfa80c5aae29b519063902734$
//

#include "libcef_dll/ctocpp/request_handler_ctocpp.h"
#include "libcef_dll/cpptoc/auth_callback_cpptoc.h"
#include "libcef_dll/cpptoc/browser_cpptoc.h"
#include "libcef_dll/cpptoc/frame_cpptoc.h"
#include "libcef_dll/cpptoc/request_callback_cpptoc.h"
#include "libcef_dll/cpptoc/request_cpptoc.h"
#include "libcef_dll/cpptoc/response_cpptoc.h"
#include "libcef_dll/cpptoc/select_client_certificate_callback_cpptoc.h"
#include "libcef_dll/cpptoc/sslinfo_cpptoc.h"
#include "libcef_dll/cpptoc/x509certificate_cpptoc.h"
#include "libcef_dll/ctocpp/resource_handler_ctocpp.h"
#include "libcef_dll/ctocpp/response_filter_ctocpp.h"
#include "libcef_dll/shutdown_checker.h"

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
bool CefRequestHandlerCToCpp::OnBeforeBrowse(CefRefPtr<CefBrowser> browser,
                                             CefRefPtr<CefFrame> frame,
                                             CefRefPtr<CefRequest> request,
                                             bool user_gesture,
                                             bool is_redirect) {
  shutdown_checker::AssertNotShutdown();

  cef_request_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, on_before_browse))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return false;
  // Verify param: frame; type: refptr_diff
  DCHECK(frame.get());
  if (!frame.get())
    return false;
  // Verify param: request; type: refptr_diff
  DCHECK(request.get());
  if (!request.get())
    return false;

  // Execute
  int _retval = _struct->on_before_browse(
      _struct, CefBrowserCppToC::Wrap(browser), CefFrameCppToC::Wrap(frame),
      CefRequestCppToC::Wrap(request), user_gesture, is_redirect);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefRequestHandlerCToCpp::OnOpenURLFromTab(
    CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    const CefString& target_url,
    WindowOpenDisposition target_disposition,
    bool user_gesture) {
  shutdown_checker::AssertNotShutdown();

  cef_request_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, on_open_urlfrom_tab))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return false;
  // Verify param: frame; type: refptr_diff
  DCHECK(frame.get());
  if (!frame.get())
    return false;
  // Verify param: target_url; type: string_byref_const
  DCHECK(!target_url.empty());
  if (target_url.empty())
    return false;

  // Execute
  int _retval = _struct->on_open_urlfrom_tab(
      _struct, CefBrowserCppToC::Wrap(browser), CefFrameCppToC::Wrap(frame),
      target_url.GetStruct(), target_disposition, user_gesture);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
CefRequestHandler::ReturnValue CefRequestHandlerCToCpp::OnBeforeResourceLoad(
    CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    CefRefPtr<CefRequest> request,
    CefRefPtr<CefRequestCallback> callback) {
  shutdown_checker::AssertNotShutdown();

  cef_request_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, on_before_resource_load))
    return RV_CONTINUE;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return RV_CONTINUE;
  // Verify param: frame; type: refptr_diff
  DCHECK(frame.get());
  if (!frame.get())
    return RV_CONTINUE;
  // Verify param: request; type: refptr_diff
  DCHECK(request.get());
  if (!request.get())
    return RV_CONTINUE;
  // Verify param: callback; type: refptr_diff
  DCHECK(callback.get());
  if (!callback.get())
    return RV_CONTINUE;

  // Execute
  cef_return_value_t _retval = _struct->on_before_resource_load(
      _struct, CefBrowserCppToC::Wrap(browser), CefFrameCppToC::Wrap(frame),
      CefRequestCppToC::Wrap(request),
      CefRequestCallbackCppToC::Wrap(callback));

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefResourceHandler> CefRequestHandlerCToCpp::GetResourceHandler(
    CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    CefRefPtr<CefRequest> request) {
  shutdown_checker::AssertNotShutdown();

  cef_request_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_resource_handler))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return NULL;
  // Verify param: frame; type: refptr_diff
  DCHECK(frame.get());
  if (!frame.get())
    return NULL;
  // Verify param: request; type: refptr_diff
  DCHECK(request.get());
  if (!request.get())
    return NULL;

  // Execute
  cef_resource_handler_t* _retval = _struct->get_resource_handler(
      _struct, CefBrowserCppToC::Wrap(browser), CefFrameCppToC::Wrap(frame),
      CefRequestCppToC::Wrap(request));

  // Return type: refptr_same
  return CefResourceHandlerCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
void CefRequestHandlerCToCpp::OnResourceRedirect(
    CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    CefRefPtr<CefRequest> request,
    CefRefPtr<CefResponse> response,
    CefString& new_url) {
  shutdown_checker::AssertNotShutdown();

  cef_request_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, on_resource_redirect))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return;
  // Verify param: frame; type: refptr_diff
  DCHECK(frame.get());
  if (!frame.get())
    return;
  // Verify param: request; type: refptr_diff
  DCHECK(request.get());
  if (!request.get())
    return;
  // Verify param: response; type: refptr_diff
  DCHECK(response.get());
  if (!response.get())
    return;

  // Execute
  _struct->on_resource_redirect(
      _struct, CefBrowserCppToC::Wrap(browser), CefFrameCppToC::Wrap(frame),
      CefRequestCppToC::Wrap(request), CefResponseCppToC::Wrap(response),
      new_url.GetWritableStruct());
}

NO_SANITIZE("cfi-icall")
bool CefRequestHandlerCToCpp::OnResourceResponse(
    CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    CefRefPtr<CefRequest> request,
    CefRefPtr<CefResponse> response) {
  shutdown_checker::AssertNotShutdown();

  cef_request_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, on_resource_response))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return false;
  // Verify param: frame; type: refptr_diff
  DCHECK(frame.get());
  if (!frame.get())
    return false;
  // Verify param: request; type: refptr_diff
  DCHECK(request.get());
  if (!request.get())
    return false;
  // Verify param: response; type: refptr_diff
  DCHECK(response.get());
  if (!response.get())
    return false;

  // Execute
  int _retval = _struct->on_resource_response(
      _struct, CefBrowserCppToC::Wrap(browser), CefFrameCppToC::Wrap(frame),
      CefRequestCppToC::Wrap(request), CefResponseCppToC::Wrap(response));

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefResponseFilter> CefRequestHandlerCToCpp::GetResourceResponseFilter(
    CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    CefRefPtr<CefRequest> request,
    CefRefPtr<CefResponse> response) {
  shutdown_checker::AssertNotShutdown();

  cef_request_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_resource_response_filter))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return NULL;
  // Verify param: frame; type: refptr_diff
  DCHECK(frame.get());
  if (!frame.get())
    return NULL;
  // Verify param: request; type: refptr_diff
  DCHECK(request.get());
  if (!request.get())
    return NULL;
  // Verify param: response; type: refptr_diff
  DCHECK(response.get());
  if (!response.get())
    return NULL;

  // Execute
  cef_response_filter_t* _retval = _struct->get_resource_response_filter(
      _struct, CefBrowserCppToC::Wrap(browser), CefFrameCppToC::Wrap(frame),
      CefRequestCppToC::Wrap(request), CefResponseCppToC::Wrap(response));

  // Return type: refptr_same
  return CefResponseFilterCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
void CefRequestHandlerCToCpp::OnResourceLoadComplete(
    CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    CefRefPtr<CefRequest> request,
    CefRefPtr<CefResponse> response,
    URLRequestStatus status,
    int64 received_content_length) {
  shutdown_checker::AssertNotShutdown();

  cef_request_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, on_resource_load_complete))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return;
  // Verify param: frame; type: refptr_diff
  DCHECK(frame.get());
  if (!frame.get())
    return;
  // Verify param: request; type: refptr_diff
  DCHECK(request.get());
  if (!request.get())
    return;
  // Verify param: response; type: refptr_diff
  DCHECK(response.get());
  if (!response.get())
    return;

  // Execute
  _struct->on_resource_load_complete(
      _struct, CefBrowserCppToC::Wrap(browser), CefFrameCppToC::Wrap(frame),
      CefRequestCppToC::Wrap(request), CefResponseCppToC::Wrap(response),
      status, received_content_length);
}

NO_SANITIZE("cfi-icall")
bool CefRequestHandlerCToCpp::GetAuthCredentials(
    CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    bool isProxy,
    const CefString& host,
    int port,
    const CefString& realm,
    const CefString& scheme,
    CefRefPtr<CefAuthCallback> callback) {
  shutdown_checker::AssertNotShutdown();

  cef_request_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_auth_credentials))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return false;
  // Verify param: frame; type: refptr_diff
  DCHECK(frame.get());
  if (!frame.get())
    return false;
  // Verify param: host; type: string_byref_const
  DCHECK(!host.empty());
  if (host.empty())
    return false;
  // Verify param: callback; type: refptr_diff
  DCHECK(callback.get());
  if (!callback.get())
    return false;
  // Unverified params: realm, scheme

  // Execute
  int _retval = _struct->get_auth_credentials(
      _struct, CefBrowserCppToC::Wrap(browser), CefFrameCppToC::Wrap(frame),
      isProxy, host.GetStruct(), port, realm.GetStruct(), scheme.GetStruct(),
      CefAuthCallbackCppToC::Wrap(callback));

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefRequestHandlerCToCpp::CanGetCookies(CefRefPtr<CefBrowser> browser,
                                            CefRefPtr<CefFrame> frame,
                                            CefRefPtr<CefRequest> request) {
  shutdown_checker::AssertNotShutdown();

  cef_request_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, can_get_cookies))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return false;
  // Verify param: frame; type: refptr_diff
  DCHECK(frame.get());
  if (!frame.get())
    return false;
  // Verify param: request; type: refptr_diff
  DCHECK(request.get());
  if (!request.get())
    return false;

  // Execute
  int _retval = _struct->can_get_cookies(
      _struct, CefBrowserCppToC::Wrap(browser), CefFrameCppToC::Wrap(frame),
      CefRequestCppToC::Wrap(request));

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefRequestHandlerCToCpp::CanSetCookie(CefRefPtr<CefBrowser> browser,
                                           CefRefPtr<CefFrame> frame,
                                           CefRefPtr<CefRequest> request,
                                           const CefCookie& cookie) {
  shutdown_checker::AssertNotShutdown();

  cef_request_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, can_set_cookie))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return false;
  // Verify param: frame; type: refptr_diff
  DCHECK(frame.get());
  if (!frame.get())
    return false;
  // Verify param: request; type: refptr_diff
  DCHECK(request.get());
  if (!request.get())
    return false;

  // Execute
  int _retval = _struct->can_set_cookie(
      _struct, CefBrowserCppToC::Wrap(browser), CefFrameCppToC::Wrap(frame),
      CefRequestCppToC::Wrap(request), &cookie);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefRequestHandlerCToCpp::OnQuotaRequest(
    CefRefPtr<CefBrowser> browser,
    const CefString& origin_url,
    int64 new_size,
    CefRefPtr<CefRequestCallback> callback) {
  shutdown_checker::AssertNotShutdown();

  cef_request_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, on_quota_request))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return false;
  // Verify param: origin_url; type: string_byref_const
  DCHECK(!origin_url.empty());
  if (origin_url.empty())
    return false;
  // Verify param: callback; type: refptr_diff
  DCHECK(callback.get());
  if (!callback.get())
    return false;

  // Execute
  int _retval = _struct->on_quota_request(
      _struct, CefBrowserCppToC::Wrap(browser), origin_url.GetStruct(),
      new_size, CefRequestCallbackCppToC::Wrap(callback));

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
void CefRequestHandlerCToCpp::OnProtocolExecution(CefRefPtr<CefBrowser> browser,
                                                  const CefString& url,
                                                  bool& allow_os_execution) {
  shutdown_checker::AssertNotShutdown();

  cef_request_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, on_protocol_execution))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return;
  // Verify param: url; type: string_byref_const
  DCHECK(!url.empty());
  if (url.empty())
    return;

  // Translate param: allow_os_execution; type: bool_byref
  int allow_os_executionInt = allow_os_execution;

  // Execute
  _struct->on_protocol_execution(_struct, CefBrowserCppToC::Wrap(browser),
                                 url.GetStruct(), &allow_os_executionInt);

  // Restore param:allow_os_execution; type: bool_byref
  allow_os_execution = allow_os_executionInt ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefRequestHandlerCToCpp::OnCertificateError(
    CefRefPtr<CefBrowser> browser,
    cef_errorcode_t cert_error,
    const CefString& request_url,
    CefRefPtr<CefSSLInfo> ssl_info,
    CefRefPtr<CefRequestCallback> callback) {
  shutdown_checker::AssertNotShutdown();

  cef_request_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, on_certificate_error))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return false;
  // Verify param: request_url; type: string_byref_const
  DCHECK(!request_url.empty());
  if (request_url.empty())
    return false;
  // Verify param: ssl_info; type: refptr_diff
  DCHECK(ssl_info.get());
  if (!ssl_info.get())
    return false;
  // Verify param: callback; type: refptr_diff
  DCHECK(callback.get());
  if (!callback.get())
    return false;

  // Execute
  int _retval = _struct->on_certificate_error(
      _struct, CefBrowserCppToC::Wrap(browser), cert_error,
      request_url.GetStruct(), CefSSLInfoCppToC::Wrap(ssl_info),
      CefRequestCallbackCppToC::Wrap(callback));

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefRequestHandlerCToCpp::OnSelectClientCertificate(
    CefRefPtr<CefBrowser> browser,
    bool isProxy,
    const CefString& host,
    int port,
    const X509CertificateList& certificates,
    CefRefPtr<CefSelectClientCertificateCallback> callback) {
  shutdown_checker::AssertNotShutdown();

  cef_request_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, on_select_client_certificate))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return false;
  // Verify param: host; type: string_byref_const
  DCHECK(!host.empty());
  if (host.empty())
    return false;
  // Verify param: callback; type: refptr_diff
  DCHECK(callback.get());
  if (!callback.get())
    return false;

  // Translate param: certificates; type: refptr_vec_diff_byref_const
  const size_t certificatesCount = certificates.size();
  cef_x509certificate_t** certificatesList = NULL;
  if (certificatesCount > 0) {
    certificatesList = new cef_x509certificate_t*[certificatesCount];
    DCHECK(certificatesList);
    if (certificatesList) {
      for (size_t i = 0; i < certificatesCount; ++i) {
        certificatesList[i] = CefX509CertificateCppToC::Wrap(certificates[i]);
      }
    }
  }

  // Execute
  int _retval = _struct->on_select_client_certificate(
      _struct, CefBrowserCppToC::Wrap(browser), isProxy, host.GetStruct(), port,
      certificatesCount, certificatesList,
      CefSelectClientCertificateCallbackCppToC::Wrap(callback));

  // Restore param:certificates; type: refptr_vec_diff_byref_const
  if (certificatesList)
    delete[] certificatesList;

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
void CefRequestHandlerCToCpp::OnPluginCrashed(CefRefPtr<CefBrowser> browser,
                                              const CefString& plugin_path) {
  shutdown_checker::AssertNotShutdown();

  cef_request_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, on_plugin_crashed))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return;
  // Verify param: plugin_path; type: string_byref_const
  DCHECK(!plugin_path.empty());
  if (plugin_path.empty())
    return;

  // Execute
  _struct->on_plugin_crashed(_struct, CefBrowserCppToC::Wrap(browser),
                             plugin_path.GetStruct());
}

NO_SANITIZE("cfi-icall")
void CefRequestHandlerCToCpp::OnRenderViewReady(CefRefPtr<CefBrowser> browser) {
  shutdown_checker::AssertNotShutdown();

  cef_request_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, on_render_view_ready))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return;

  // Execute
  _struct->on_render_view_ready(_struct, CefBrowserCppToC::Wrap(browser));
}

NO_SANITIZE("cfi-icall")
void CefRequestHandlerCToCpp::OnRenderProcessTerminated(
    CefRefPtr<CefBrowser> browser,
    TerminationStatus status) {
  shutdown_checker::AssertNotShutdown();

  cef_request_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, on_render_process_terminated))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return;

  // Execute
  _struct->on_render_process_terminated(
      _struct, CefBrowserCppToC::Wrap(browser), status);
}

// CONSTRUCTOR - Do not edit by hand.

CefRequestHandlerCToCpp::CefRequestHandlerCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

CefRequestHandlerCToCpp::~CefRequestHandlerCToCpp() {
  shutdown_checker::AssertNotShutdown();
}

template <>
cef_request_handler_t* CefCToCppRefCounted<
    CefRequestHandlerCToCpp,
    CefRequestHandler,
    cef_request_handler_t>::UnwrapDerived(CefWrapperType type,
                                          CefRequestHandler* c) {
  NOTREACHED() << "Unexpected class type: " << type;
  return NULL;
}

#if DCHECK_IS_ON()
template <>
base::AtomicRefCount CefCToCppRefCounted<CefRequestHandlerCToCpp,
                                         CefRequestHandler,
                                         cef_request_handler_t>::DebugObjCt
    ATOMIC_DECLARATION;
#endif

template <>
CefWrapperType CefCToCppRefCounted<CefRequestHandlerCToCpp,
                                   CefRequestHandler,
                                   cef_request_handler_t>::kWrapperType =
    WT_REQUEST_HANDLER;
