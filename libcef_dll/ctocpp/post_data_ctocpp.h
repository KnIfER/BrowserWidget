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

#ifndef CEF_LIBCEF_DLL_CTOCPP_POST_DATA_CTOCPP_H_
#define CEF_LIBCEF_DLL_CTOCPP_POST_DATA_CTOCPP_H_
#pragma once

#ifndef USING_CEF_SHARED
#pragma message("Warning: "__FILE__" may be accessed wrapper-side only")
#else  // USING_CEF_SHARED

#include "include/cef_request.h"
#include "include/capi/cef_request_capi.h"
#include "libcef_dll/ctocpp/ctocpp.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed wrapper-side only.
class CefPostDataCToCpp
    : public CefCToCpp<CefPostDataCToCpp, CefPostData, cef_post_data_t> {
 public:
  CefPostDataCToCpp();

  // CefPostData methods.
  bool IsReadOnly() OVERRIDE;
  size_t GetElementCount() OVERRIDE;
  void GetElements(ElementVector& elements) OVERRIDE;
  bool RemoveElement(CefRefPtr<CefPostDataElement> element) OVERRIDE;
  bool AddElement(CefRefPtr<CefPostDataElement> element) OVERRIDE;
  void RemoveElements() OVERRIDE;
};

#endif  // USING_CEF_SHARED
#endif  // CEF_LIBCEF_DLL_CTOCPP_POST_DATA_CTOCPP_H_
