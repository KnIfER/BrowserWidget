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
// $hash=16f2fc491196c37d41c1f1a15c0137c47581df40$
//

#ifndef CEF_LIBCEF_DLL_CTOCPP_RUN_FILE_DIALOG_CALLBACK_CTOCPP_H_
#define CEF_LIBCEF_DLL_CTOCPP_RUN_FILE_DIALOG_CALLBACK_CTOCPP_H_
#pragma once

#if !defined(BUILDING_CEF_SHARED)
#error This file can be included DLL-side only
#endif

#include <vector>
#include "include/capi/cef_browser_capi.h"
#include "include/capi/cef_client_capi.h"
#include "include/cef_browser.h"
#include "include/cef_client.h"
#include "libcef_dll/ctocpp/ctocpp_ref_counted.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed DLL-side only.
class CefRunFileDialogCallbackCToCpp
    : public CefCToCppRefCounted<CefRunFileDialogCallbackCToCpp,
                                 CefRunFileDialogCallback,
                                 cef_run_file_dialog_callback_t> {
 public:
  CefRunFileDialogCallbackCToCpp();

  // CefRunFileDialogCallback methods.
  void OnFileDialogDismissed(int selected_accept_filter,
                             const std::vector<CefString>& file_paths) override;
};

#endif  // CEF_LIBCEF_DLL_CTOCPP_RUN_FILE_DIALOG_CALLBACK_CTOCPP_H_
