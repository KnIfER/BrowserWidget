// Copyright (c) 2016 The Chromium Embedded Framework Authors. All rights
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

#ifndef CEF_LIBCEF_DLL_CTOCPP_X509CERTIFICATE_CTOCPP_H_
#define CEF_LIBCEF_DLL_CTOCPP_X509CERTIFICATE_CTOCPP_H_
#pragma once

#ifndef USING_CEF_SHARED
#pragma message("Warning: "__FILE__" may be accessed wrapper-side only")
#else  // USING_CEF_SHARED

#include "include/cef_x509_certificate.h"
#include "include/capi/cef_x509_certificate_capi.h"
#include "libcef_dll/ctocpp/ctocpp.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed wrapper-side only.
class CefX509CertificateCToCpp
    : public CefCToCpp<CefX509CertificateCToCpp, CefX509Certificate,
        cef_x509certificate_t> {
 public:
  CefX509CertificateCToCpp();

  // CefX509Certificate methods.
  CefRefPtr<CefX509CertPrincipal> GetSubject() OVERRIDE;
  CefRefPtr<CefX509CertPrincipal> GetIssuer() OVERRIDE;
  CefRefPtr<CefBinaryValue> GetSerialNumber() OVERRIDE;
  CefTime GetValidStart() OVERRIDE;
  CefTime GetValidExpiry() OVERRIDE;
  CefRefPtr<CefBinaryValue> GetDEREncoded() OVERRIDE;
  CefRefPtr<CefBinaryValue> GetPEMEncoded() OVERRIDE;
  size_t GetIssuerChainSize() OVERRIDE;
  void GetDEREncodedIssuerChain(IssuerChainBinaryList& chain) OVERRIDE;
  void GetPEMEncodedIssuerChain(IssuerChainBinaryList& chain) OVERRIDE;
};

#endif  // USING_CEF_SHARED
#endif  // CEF_LIBCEF_DLL_CTOCPP_X509CERTIFICATE_CTOCPP_H_
