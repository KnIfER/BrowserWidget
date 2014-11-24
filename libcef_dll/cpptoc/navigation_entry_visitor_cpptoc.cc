// Copyright (c) 2014 The Chromium Embedded Framework Authors. All rights
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

#include "libcef_dll/cpptoc/navigation_entry_visitor_cpptoc.h"
#include "libcef_dll/ctocpp/navigation_entry_ctocpp.h"


// MEMBER FUNCTIONS - Body may be edited by hand.

int CEF_CALLBACK navigation_entry_visitor_visit(
    struct _cef_navigation_entry_visitor_t* self,
    struct _cef_navigation_entry_t* entry, int current, int index,
    int total) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: entry; type: refptr_diff
  DCHECK(entry);
  if (!entry)
    return 0;

  // Execute
  bool _retval = CefNavigationEntryVisitorCppToC::Get(self)->Visit(
      CefNavigationEntryCToCpp::Wrap(entry),
      current?true:false,
      index,
      total);

  // Return type: bool
  return _retval;
}


// CONSTRUCTOR - Do not edit by hand.

CefNavigationEntryVisitorCppToC::CefNavigationEntryVisitorCppToC(
    CefNavigationEntryVisitor* cls)
    : CefCppToC<CefNavigationEntryVisitorCppToC, CefNavigationEntryVisitor,
        cef_navigation_entry_visitor_t>(cls) {
  struct_.struct_.visit = navigation_entry_visitor_visit;
}

#ifndef NDEBUG
template<> base::AtomicRefCount CefCppToC<CefNavigationEntryVisitorCppToC,
    CefNavigationEntryVisitor, cef_navigation_entry_visitor_t>::DebugObjCt =
    0;
#endif

