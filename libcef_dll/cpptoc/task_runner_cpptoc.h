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
// $hash=a6b45e734c24e3157437bc0ff368ae54f53e90ca$
//

#ifndef CEF_LIBCEF_DLL_CPPTOC_TASK_RUNNER_CPPTOC_H_
#define CEF_LIBCEF_DLL_CPPTOC_TASK_RUNNER_CPPTOC_H_
#pragma once

#if !defined(BUILDING_CEF_SHARED)
#error This file can be included DLL-side only
#endif

#include "include/capi/cef_task_capi.h"
#include "include/cef_task.h"
#include "libcef_dll/cpptoc/cpptoc_ref_counted.h"

// Wrap a C++ class with a C structure.
// This class may be instantiated and accessed DLL-side only.
class CefTaskRunnerCppToC : public CefCppToCRefCounted<CefTaskRunnerCppToC,
                                                       CefTaskRunner,
                                                       cef_task_runner_t> {
 public:
  CefTaskRunnerCppToC();
  virtual ~CefTaskRunnerCppToC();
};

#endif  // CEF_LIBCEF_DLL_CPPTOC_TASK_RUNNER_CPPTOC_H_
