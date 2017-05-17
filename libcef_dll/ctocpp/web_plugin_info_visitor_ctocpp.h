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
// $hash=a589058a89323c1e870abae591d9b56810a7c679$
//

#ifndef CEF_LIBCEF_DLL_CTOCPP_WEB_PLUGIN_INFO_VISITOR_CTOCPP_H_
#define CEF_LIBCEF_DLL_CTOCPP_WEB_PLUGIN_INFO_VISITOR_CTOCPP_H_
#pragma once

#if !defined(BUILDING_CEF_SHARED)
#error This file can be included DLL-side only
#endif

#include "include/capi/cef_browser_capi.h"
#include "include/capi/cef_web_plugin_capi.h"
#include "include/cef_browser.h"
#include "include/cef_web_plugin.h"
#include "libcef_dll/ctocpp/ctocpp_ref_counted.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed DLL-side only.
class CefWebPluginInfoVisitorCToCpp
    : public CefCToCppRefCounted<CefWebPluginInfoVisitorCToCpp,
                                 CefWebPluginInfoVisitor,
                                 cef_web_plugin_info_visitor_t> {
 public:
  CefWebPluginInfoVisitorCToCpp();

  // CefWebPluginInfoVisitor methods.
  bool Visit(CefRefPtr<CefWebPluginInfo> info, int count, int total) override;
};

#endif  // CEF_LIBCEF_DLL_CTOCPP_WEB_PLUGIN_INFO_VISITOR_CTOCPP_H_
