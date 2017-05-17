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
// $hash=9fe7fa4988fcebbb7ceee4d283c265fb069d5b7b$
//

#ifndef CEF_LIBCEF_DLL_CPPTOC_FILE_DIALOG_CALLBACK_CPPTOC_H_
#define CEF_LIBCEF_DLL_CPPTOC_FILE_DIALOG_CALLBACK_CPPTOC_H_
#pragma once

#if !defined(BUILDING_CEF_SHARED)
#error This file can be included DLL-side only
#endif

#include "include/capi/cef_dialog_handler_capi.h"
#include "include/cef_dialog_handler.h"
#include "libcef_dll/cpptoc/cpptoc_ref_counted.h"

// Wrap a C++ class with a C structure.
// This class may be instantiated and accessed DLL-side only.
class CefFileDialogCallbackCppToC
    : public CefCppToCRefCounted<CefFileDialogCallbackCppToC,
                                 CefFileDialogCallback,
                                 cef_file_dialog_callback_t> {
 public:
  CefFileDialogCallbackCppToC();
};

#endif  // CEF_LIBCEF_DLL_CPPTOC_FILE_DIALOG_CALLBACK_CPPTOC_H_
