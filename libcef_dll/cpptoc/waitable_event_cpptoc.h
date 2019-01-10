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
// $hash=8460ceaa3e43ec8e41eefcfe923e1b52ae553f07$
//

#ifndef CEF_LIBCEF_DLL_CPPTOC_WAITABLE_EVENT_CPPTOC_H_
#define CEF_LIBCEF_DLL_CPPTOC_WAITABLE_EVENT_CPPTOC_H_
#pragma once

#if !defined(BUILDING_CEF_SHARED)
#error This file can be included DLL-side only
#endif

#include "include/capi/cef_waitable_event_capi.h"
#include "include/cef_waitable_event.h"
#include "libcef_dll/cpptoc/cpptoc_ref_counted.h"

// Wrap a C++ class with a C structure.
// This class may be instantiated and accessed DLL-side only.
class CefWaitableEventCppToC
    : public CefCppToCRefCounted<CefWaitableEventCppToC,
                                 CefWaitableEvent,
                                 cef_waitable_event_t> {
 public:
  CefWaitableEventCppToC();
};

#endif  // CEF_LIBCEF_DLL_CPPTOC_WAITABLE_EVENT_CPPTOC_H_
