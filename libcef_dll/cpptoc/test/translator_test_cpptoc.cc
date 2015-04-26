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

#include <algorithm>
#include "libcef_dll/cpptoc/test/translator_test_cpptoc.h"
#include "libcef_dll/cpptoc/test/translator_test_object_cpptoc.h"
#include "libcef_dll/cpptoc/test/translator_test_object_child_cpptoc.h"
#include "libcef_dll/ctocpp/test/translator_test_handler_ctocpp.h"
#include "libcef_dll/ctocpp/test/translator_test_handler_child_ctocpp.h"
#include "libcef_dll/transfer_util.h"


// GLOBAL FUNCTIONS - Body may be edited by hand.

CEF_EXPORT cef_translator_test_t* cef_translator_test_create() {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  CefRefPtr<CefTranslatorTest> _retval = CefTranslatorTest::Create();

  // Return type: refptr_same
  return CefTranslatorTestCppToC::Wrap(_retval);
}


namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

void CEF_CALLBACK translator_test_get_void(
    struct _cef_translator_test_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefTranslatorTestCppToC::Get(self)->GetVoid();
}

int CEF_CALLBACK translator_test_get_bool(struct _cef_translator_test_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefTranslatorTestCppToC::Get(self)->GetBool();

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK translator_test_get_int(struct _cef_translator_test_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  int _retval = CefTranslatorTestCppToC::Get(self)->GetInt();

  // Return type: simple
  return _retval;
}

double CEF_CALLBACK translator_test_get_double(
    struct _cef_translator_test_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  double _retval = CefTranslatorTestCppToC::Get(self)->GetDouble();

  // Return type: simple
  return _retval;
}

long CEF_CALLBACK translator_test_get_long(
    struct _cef_translator_test_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  long _retval = CefTranslatorTestCppToC::Get(self)->GetLong();

  // Return type: simple
  return _retval;
}

size_t CEF_CALLBACK translator_test_get_sizet(
    struct _cef_translator_test_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  size_t _retval = CefTranslatorTestCppToC::Get(self)->GetSizet();

  // Return type: simple
  return _retval;
}

int CEF_CALLBACK translator_test_set_void(struct _cef_translator_test_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefTranslatorTestCppToC::Get(self)->SetVoid();

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK translator_test_set_bool(struct _cef_translator_test_t* self,
    int val) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefTranslatorTestCppToC::Get(self)->SetBool(
      val?true:false);

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK translator_test_set_int(struct _cef_translator_test_t* self,
    int val) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefTranslatorTestCppToC::Get(self)->SetInt(
      val);

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK translator_test_set_double(struct _cef_translator_test_t* self,
    double val) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefTranslatorTestCppToC::Get(self)->SetDouble(
      val);

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK translator_test_set_long(struct _cef_translator_test_t* self,
    long val) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefTranslatorTestCppToC::Get(self)->SetLong(
      val);

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK translator_test_set_sizet(struct _cef_translator_test_t* self,
    size_t val) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefTranslatorTestCppToC::Get(self)->SetSizet(
      val);

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK translator_test_set_int_list(
    struct _cef_translator_test_t* self, size_t valCount, int const* val) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: val; type: simple_vec_byref_const
  DCHECK(valCount == 0 || val);
  if (valCount > 0 && !val)
    return 0;

  // Translate param: val; type: simple_vec_byref_const
  std::vector<int > valList;
  if (valCount > 0) {
    for (size_t i = 0; i < valCount; ++i) {
      valList.push_back(val[i]);
    }
  }

  // Execute
  bool _retval = CefTranslatorTestCppToC::Get(self)->SetIntList(
      valList);

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK translator_test_get_int_list_by_ref(
    struct _cef_translator_test_t* self, size_t* valCount, int* val) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: val; type: simple_vec_byref
  DCHECK(valCount && (*valCount == 0 || val));
  if (!valCount || (*valCount > 0 && !val))
    return 0;

  // Translate param: val; type: simple_vec_byref
  std::vector<int > valList;
  if (valCount && *valCount > 0 && val) {
    for (size_t i = 0; i < *valCount; ++i) {
      valList.push_back(val[i]);
    }
  }

  // Execute
  bool _retval = CefTranslatorTestCppToC::Get(self)->GetIntListByRef(
      valList);

  // Restore param: val; type: simple_vec_byref
  if (valCount && val) {
    *valCount = std::min(valList.size(), *valCount);
    if (*valCount > 0) {
      for (size_t i = 0; i < *valCount; ++i) {
        val[i] = valList[i];
      }
    }
  }

  // Return type: bool
  return _retval;
}

size_t CEF_CALLBACK translator_test_get_int_list_size(
    struct _cef_translator_test_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  size_t _retval = CefTranslatorTestCppToC::Get(self)->GetIntListSize();

  // Return type: simple
  return _retval;
}

cef_string_userfree_t CEF_CALLBACK translator_test_get_string(
    struct _cef_translator_test_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefTranslatorTestCppToC::Get(self)->GetString();

  // Return type: string
  return _retval.DetachToUserFree();
}

int CEF_CALLBACK translator_test_set_string(struct _cef_translator_test_t* self,
    const cef_string_t* val) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: val; type: string_byref_const
  DCHECK(val);
  if (!val)
    return 0;

  // Execute
  bool _retval = CefTranslatorTestCppToC::Get(self)->SetString(
      CefString(val));

  // Return type: bool
  return _retval;
}

void CEF_CALLBACK translator_test_get_string_by_ref(
    struct _cef_translator_test_t* self, cef_string_t* val) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: val; type: string_byref
  DCHECK(val);
  if (!val)
    return;

  // Translate param: val; type: string_byref
  CefString valStr(val);

  // Execute
  CefTranslatorTestCppToC::Get(self)->GetStringByRef(
      valStr);
}

int CEF_CALLBACK translator_test_set_string_list(
    struct _cef_translator_test_t* self, cef_string_list_t val) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: val; type: string_vec_byref_const
  DCHECK(val);
  if (!val)
    return 0;

  // Translate param: val; type: string_vec_byref_const
  std::vector<CefString> valList;
  transfer_string_list_contents(val, valList);

  // Execute
  bool _retval = CefTranslatorTestCppToC::Get(self)->SetStringList(
      valList);

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK translator_test_get_string_list_by_ref(
    struct _cef_translator_test_t* self, cef_string_list_t val) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: val; type: string_vec_byref
  DCHECK(val);
  if (!val)
    return 0;

  // Translate param: val; type: string_vec_byref
  std::vector<CefString> valList;
  transfer_string_list_contents(val, valList);

  // Execute
  bool _retval = CefTranslatorTestCppToC::Get(self)->GetStringListByRef(
      valList);

  // Restore param: val; type: string_vec_byref
  cef_string_list_clear(val);
  transfer_string_list_contents(valList, val);

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK translator_test_set_string_map(
    struct _cef_translator_test_t* self, cef_string_map_t val) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: val; type: string_map_single_byref_const
  DCHECK(val);
  if (!val)
    return 0;

  // Translate param: val; type: string_map_single_byref_const
  std::map<CefString, CefString> valMap;
  transfer_string_map_contents(val, valMap);

  // Execute
  bool _retval = CefTranslatorTestCppToC::Get(self)->SetStringMap(
      valMap);

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK translator_test_get_string_map_by_ref(
    struct _cef_translator_test_t* self, cef_string_map_t val) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: val; type: string_map_single_byref
  DCHECK(val);
  if (!val)
    return 0;

  // Translate param: val; type: string_map_single_byref
  std::map<CefString, CefString> valMap;
  transfer_string_map_contents(val, valMap);

  // Execute
  bool _retval = CefTranslatorTestCppToC::Get(self)->GetStringMapByRef(
      valMap);

  // Restore param: val; type: string_map_single_byref
  cef_string_map_clear(val);
  transfer_string_map_contents(valMap, val);

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK translator_test_set_string_multimap(
    struct _cef_translator_test_t* self, cef_string_multimap_t val) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: val; type: string_map_multi_byref_const
  DCHECK(val);
  if (!val)
    return 0;

  // Translate param: val; type: string_map_multi_byref_const
  std::multimap<CefString, CefString> valMultimap;
  transfer_string_multimap_contents(val, valMultimap);

  // Execute
  bool _retval = CefTranslatorTestCppToC::Get(self)->SetStringMultimap(
      valMultimap);

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK translator_test_get_string_multimap_by_ref(
    struct _cef_translator_test_t* self, cef_string_multimap_t val) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: val; type: string_map_multi_byref
  DCHECK(val);
  if (!val)
    return 0;

  // Translate param: val; type: string_map_multi_byref
  std::multimap<CefString, CefString> valMultimap;
  transfer_string_multimap_contents(val, valMultimap);

  // Execute
  bool _retval = CefTranslatorTestCppToC::Get(self)->GetStringMultimapByRef(
      valMultimap);

  // Restore param: val; type: string_map_multi_byref
  cef_string_multimap_clear(val);
  transfer_string_multimap_contents(valMultimap, val);

  // Return type: bool
  return _retval;
}

cef_point_t CEF_CALLBACK translator_test_get_point(
    struct _cef_translator_test_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return CefPoint();

  // Execute
  cef_point_t _retval = CefTranslatorTestCppToC::Get(self)->GetPoint();

  // Return type: simple
  return _retval;
}

int CEF_CALLBACK translator_test_set_point(struct _cef_translator_test_t* self,
    const cef_point_t* val) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: val; type: simple_byref_const
  DCHECK(val);
  if (!val)
    return 0;

  // Translate param: val; type: simple_byref_const
  CefPoint valVal = val?*val:CefPoint();

  // Execute
  bool _retval = CefTranslatorTestCppToC::Get(self)->SetPoint(
      valVal);

  // Return type: bool
  return _retval;
}

void CEF_CALLBACK translator_test_get_point_by_ref(
    struct _cef_translator_test_t* self, cef_point_t* val) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: val; type: simple_byref
  DCHECK(val);
  if (!val)
    return;

  // Translate param: val; type: simple_byref
  CefPoint valVal = val?*val:CefPoint();

  // Execute
  CefTranslatorTestCppToC::Get(self)->GetPointByRef(
      valVal);

  // Restore param: val; type: simple_byref
  if (val)
    *val = valVal;
}

int CEF_CALLBACK translator_test_set_point_list(
    struct _cef_translator_test_t* self, size_t valCount,
    cef_point_t const* val) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: val; type: simple_vec_byref_const
  DCHECK(valCount == 0 || val);
  if (valCount > 0 && !val)
    return 0;

  // Translate param: val; type: simple_vec_byref_const
  std::vector<CefPoint > valList;
  if (valCount > 0) {
    for (size_t i = 0; i < valCount; ++i) {
      valList.push_back(val[i]);
    }
  }

  // Execute
  bool _retval = CefTranslatorTestCppToC::Get(self)->SetPointList(
      valList);

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK translator_test_get_point_list_by_ref(
    struct _cef_translator_test_t* self, size_t* valCount, cef_point_t* val) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: val; type: simple_vec_byref
  DCHECK(valCount && (*valCount == 0 || val));
  if (!valCount || (*valCount > 0 && !val))
    return 0;

  // Translate param: val; type: simple_vec_byref
  std::vector<CefPoint > valList;
  if (valCount && *valCount > 0 && val) {
    for (size_t i = 0; i < *valCount; ++i) {
      valList.push_back(val[i]);
    }
  }

  // Execute
  bool _retval = CefTranslatorTestCppToC::Get(self)->GetPointListByRef(
      valList);

  // Restore param: val; type: simple_vec_byref
  if (valCount && val) {
    *valCount = std::min(valList.size(), *valCount);
    if (*valCount > 0) {
      for (size_t i = 0; i < *valCount; ++i) {
        val[i] = valList[i];
      }
    }
  }

  // Return type: bool
  return _retval;
}

size_t CEF_CALLBACK translator_test_get_point_list_size(
    struct _cef_translator_test_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  size_t _retval = CefTranslatorTestCppToC::Get(self)->GetPointListSize();

  // Return type: simple
  return _retval;
}

struct _cef_translator_test_object_t* CEF_CALLBACK translator_test_get_object(
    struct _cef_translator_test_t* self, int val) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefTranslatorTestObject> _retval = CefTranslatorTestCppToC::Get(
      self)->GetObject(
      val);

  // Return type: refptr_same
  return CefTranslatorTestObjectCppToC::Wrap(_retval);
}

int CEF_CALLBACK translator_test_set_object(struct _cef_translator_test_t* self,
    struct _cef_translator_test_object_t* val) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: val; type: refptr_same
  DCHECK(val);
  if (!val)
    return 0;

  // Execute
  int _retval = CefTranslatorTestCppToC::Get(self)->SetObject(
      CefTranslatorTestObjectCppToC::Unwrap(val));

  // Return type: simple
  return _retval;
}

struct _cef_translator_test_object_t* CEF_CALLBACK translator_test_set_object_and_return(
    struct _cef_translator_test_t* self,
    struct _cef_translator_test_object_t* val) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;
  // Verify param: val; type: refptr_same
  DCHECK(val);
  if (!val)
    return NULL;

  // Execute
  CefRefPtr<CefTranslatorTestObject> _retval = CefTranslatorTestCppToC::Get(
      self)->SetObjectAndReturn(
      CefTranslatorTestObjectCppToC::Unwrap(val));

  // Return type: refptr_same
  return CefTranslatorTestObjectCppToC::Wrap(_retval);
}

int CEF_CALLBACK translator_test_set_child_object(
    struct _cef_translator_test_t* self,
    struct _cef_translator_test_object_child_t* val) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: val; type: refptr_same
  DCHECK(val);
  if (!val)
    return 0;

  // Execute
  int _retval = CefTranslatorTestCppToC::Get(self)->SetChildObject(
      CefTranslatorTestObjectChildCppToC::Unwrap(val));

  // Return type: simple
  return _retval;
}

struct _cef_translator_test_object_t* CEF_CALLBACK translator_test_set_child_object_and_return_parent(
    struct _cef_translator_test_t* self,
    struct _cef_translator_test_object_child_t* val) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;
  // Verify param: val; type: refptr_same
  DCHECK(val);
  if (!val)
    return NULL;

  // Execute
  CefRefPtr<CefTranslatorTestObject> _retval = CefTranslatorTestCppToC::Get(
      self)->SetChildObjectAndReturnParent(
      CefTranslatorTestObjectChildCppToC::Unwrap(val));

  // Return type: refptr_same
  return CefTranslatorTestObjectCppToC::Wrap(_retval);
}

int CEF_CALLBACK translator_test_set_object_list(
    struct _cef_translator_test_t* self, size_t valCount,
    struct _cef_translator_test_object_t* const* val, int val1, int val2) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: val; type: refptr_vec_same_byref_const
  DCHECK(valCount == 0 || val);
  if (valCount > 0 && !val)
    return 0;

  // Translate param: val; type: refptr_vec_same_byref_const
  std::vector<CefRefPtr<CefTranslatorTestObject> > valList;
  if (valCount > 0) {
    for (size_t i = 0; i < valCount; ++i) {
      valList.push_back(CefTranslatorTestObjectCppToC::Unwrap(val[i]));
    }
  }

  // Execute
  bool _retval = CefTranslatorTestCppToC::Get(self)->SetObjectList(
      valList,
      val1,
      val2);

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK translator_test_get_object_list_by_ref(
    struct _cef_translator_test_t* self, size_t* valCount,
    struct _cef_translator_test_object_t** val, int val1, int val2) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: val; type: refptr_vec_same_byref
  DCHECK(valCount && (*valCount == 0 || val));
  if (!valCount || (*valCount > 0 && !val))
    return 0;

  // Translate param: val; type: refptr_vec_same_byref
  std::vector<CefRefPtr<CefTranslatorTestObject> > valList;
  if (valCount && *valCount > 0 && val) {
    for (size_t i = 0; i < *valCount; ++i) {
      valList.push_back(CefTranslatorTestObjectCppToC::Unwrap(val[i]));
    }
  }

  // Execute
  bool _retval = CefTranslatorTestCppToC::Get(self)->GetObjectListByRef(
      valList,
      val1,
      val2);

  // Restore param: val; type: refptr_vec_same_byref
  if (valCount && val) {
    *valCount = std::min(valList.size(), *valCount);
    if (*valCount > 0) {
      for (size_t i = 0; i < *valCount; ++i) {
        val[i] = CefTranslatorTestObjectCppToC::Wrap(valList[i]);
      }
    }
  }

  // Return type: bool
  return _retval;
}

size_t CEF_CALLBACK translator_test_get_object_list_size(
    struct _cef_translator_test_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  size_t _retval = CefTranslatorTestCppToC::Get(self)->GetObjectListSize();

  // Return type: simple
  return _retval;
}

int CEF_CALLBACK translator_test_set_handler(
    struct _cef_translator_test_t* self,
    struct _cef_translator_test_handler_t* val) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: val; type: refptr_diff
  DCHECK(val);
  if (!val)
    return 0;

  // Execute
  int _retval = CefTranslatorTestCppToC::Get(self)->SetHandler(
      CefTranslatorTestHandlerCToCpp::Wrap(val));

  // Return type: simple
  return _retval;
}

struct _cef_translator_test_handler_t* CEF_CALLBACK translator_test_set_handler_and_return(
    struct _cef_translator_test_t* self,
    struct _cef_translator_test_handler_t* val) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;
  // Verify param: val; type: refptr_diff
  DCHECK(val);
  if (!val)
    return NULL;

  // Execute
  CefRefPtr<CefTranslatorTestHandler> _retval = CefTranslatorTestCppToC::Get(
      self)->SetHandlerAndReturn(
      CefTranslatorTestHandlerCToCpp::Wrap(val));

  // Return type: refptr_diff
  return CefTranslatorTestHandlerCToCpp::Unwrap(_retval);
}

int CEF_CALLBACK translator_test_set_child_handler(
    struct _cef_translator_test_t* self,
    struct _cef_translator_test_handler_child_t* val) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: val; type: refptr_diff
  DCHECK(val);
  if (!val)
    return 0;

  // Execute
  int _retval = CefTranslatorTestCppToC::Get(self)->SetChildHandler(
      CefTranslatorTestHandlerChildCToCpp::Wrap(val));

  // Return type: simple
  return _retval;
}

struct _cef_translator_test_handler_t* CEF_CALLBACK translator_test_set_child_handler_and_return_parent(
    struct _cef_translator_test_t* self,
    struct _cef_translator_test_handler_child_t* val) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;
  // Verify param: val; type: refptr_diff
  DCHECK(val);
  if (!val)
    return NULL;

  // Execute
  CefRefPtr<CefTranslatorTestHandler> _retval = CefTranslatorTestCppToC::Get(
      self)->SetChildHandlerAndReturnParent(
      CefTranslatorTestHandlerChildCToCpp::Wrap(val));

  // Return type: refptr_diff
  return CefTranslatorTestHandlerCToCpp::Unwrap(_retval);
}

int CEF_CALLBACK translator_test_set_handler_list(
    struct _cef_translator_test_t* self, size_t valCount,
    struct _cef_translator_test_handler_t* const* val, int val1, int val2) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: val; type: refptr_vec_diff_byref_const
  DCHECK(valCount == 0 || val);
  if (valCount > 0 && !val)
    return 0;

  // Translate param: val; type: refptr_vec_diff_byref_const
  std::vector<CefRefPtr<CefTranslatorTestHandler> > valList;
  if (valCount > 0) {
    for (size_t i = 0; i < valCount; ++i) {
      valList.push_back(CefTranslatorTestHandlerCToCpp::Wrap(val[i]));
    }
  }

  // Execute
  bool _retval = CefTranslatorTestCppToC::Get(self)->SetHandlerList(
      valList,
      val1,
      val2);

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK translator_test_get_handler_list_by_ref(
    struct _cef_translator_test_t* self, size_t* valCount,
    struct _cef_translator_test_handler_t** val,
    struct _cef_translator_test_handler_t* val1,
    struct _cef_translator_test_handler_t* val2) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: val; type: refptr_vec_diff_byref
  DCHECK(valCount && (*valCount == 0 || val));
  if (!valCount || (*valCount > 0 && !val))
    return 0;
  // Verify param: val1; type: refptr_diff
  DCHECK(val1);
  if (!val1)
    return 0;
  // Verify param: val2; type: refptr_diff
  DCHECK(val2);
  if (!val2)
    return 0;

  // Translate param: val; type: refptr_vec_diff_byref
  std::vector<CefRefPtr<CefTranslatorTestHandler> > valList;
  if (valCount && *valCount > 0 && val) {
    for (size_t i = 0; i < *valCount; ++i) {
      valList.push_back(CefTranslatorTestHandlerCToCpp::Wrap(val[i]));
    }
  }

  // Execute
  bool _retval = CefTranslatorTestCppToC::Get(self)->GetHandlerListByRef(
      valList,
      CefTranslatorTestHandlerCToCpp::Wrap(val1),
      CefTranslatorTestHandlerCToCpp::Wrap(val2));

  // Restore param: val; type: refptr_vec_diff_byref
  if (valCount && val) {
    *valCount = std::min(valList.size(), *valCount);
    if (*valCount > 0) {
      for (size_t i = 0; i < *valCount; ++i) {
        val[i] = CefTranslatorTestHandlerCToCpp::Unwrap(valList[i]);
      }
    }
  }

  // Return type: bool
  return _retval;
}

size_t CEF_CALLBACK translator_test_get_handler_list_size(
    struct _cef_translator_test_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  size_t _retval = CefTranslatorTestCppToC::Get(self)->GetHandlerListSize();

  // Return type: simple
  return _retval;
}

}  // namespace


// CONSTRUCTOR - Do not edit by hand.

CefTranslatorTestCppToC::CefTranslatorTestCppToC() {
  GetStruct()->get_void = translator_test_get_void;
  GetStruct()->get_bool = translator_test_get_bool;
  GetStruct()->get_int = translator_test_get_int;
  GetStruct()->get_double = translator_test_get_double;
  GetStruct()->get_long = translator_test_get_long;
  GetStruct()->get_sizet = translator_test_get_sizet;
  GetStruct()->set_void = translator_test_set_void;
  GetStruct()->set_bool = translator_test_set_bool;
  GetStruct()->set_int = translator_test_set_int;
  GetStruct()->set_double = translator_test_set_double;
  GetStruct()->set_long = translator_test_set_long;
  GetStruct()->set_sizet = translator_test_set_sizet;
  GetStruct()->set_int_list = translator_test_set_int_list;
  GetStruct()->get_int_list_by_ref = translator_test_get_int_list_by_ref;
  GetStruct()->get_int_list_size = translator_test_get_int_list_size;
  GetStruct()->get_string = translator_test_get_string;
  GetStruct()->set_string = translator_test_set_string;
  GetStruct()->get_string_by_ref = translator_test_get_string_by_ref;
  GetStruct()->set_string_list = translator_test_set_string_list;
  GetStruct()->get_string_list_by_ref = translator_test_get_string_list_by_ref;
  GetStruct()->set_string_map = translator_test_set_string_map;
  GetStruct()->get_string_map_by_ref = translator_test_get_string_map_by_ref;
  GetStruct()->set_string_multimap = translator_test_set_string_multimap;
  GetStruct()->get_string_multimap_by_ref =
      translator_test_get_string_multimap_by_ref;
  GetStruct()->get_point = translator_test_get_point;
  GetStruct()->set_point = translator_test_set_point;
  GetStruct()->get_point_by_ref = translator_test_get_point_by_ref;
  GetStruct()->set_point_list = translator_test_set_point_list;
  GetStruct()->get_point_list_by_ref = translator_test_get_point_list_by_ref;
  GetStruct()->get_point_list_size = translator_test_get_point_list_size;
  GetStruct()->get_object = translator_test_get_object;
  GetStruct()->set_object = translator_test_set_object;
  GetStruct()->set_object_and_return = translator_test_set_object_and_return;
  GetStruct()->set_child_object = translator_test_set_child_object;
  GetStruct()->set_child_object_and_return_parent =
      translator_test_set_child_object_and_return_parent;
  GetStruct()->set_object_list = translator_test_set_object_list;
  GetStruct()->get_object_list_by_ref = translator_test_get_object_list_by_ref;
  GetStruct()->get_object_list_size = translator_test_get_object_list_size;
  GetStruct()->set_handler = translator_test_set_handler;
  GetStruct()->set_handler_and_return = translator_test_set_handler_and_return;
  GetStruct()->set_child_handler = translator_test_set_child_handler;
  GetStruct()->set_child_handler_and_return_parent =
      translator_test_set_child_handler_and_return_parent;
  GetStruct()->set_handler_list = translator_test_set_handler_list;
  GetStruct()->get_handler_list_by_ref =
      translator_test_get_handler_list_by_ref;
  GetStruct()->get_handler_list_size = translator_test_get_handler_list_size;
}

template<> CefRefPtr<CefTranslatorTest> CefCppToC<CefTranslatorTestCppToC,
    CefTranslatorTest, cef_translator_test_t>::UnwrapDerived(
    CefWrapperType type, cef_translator_test_t* s) {
  NOTREACHED() << "Unexpected class type: " << type;
  return NULL;
}

#ifndef NDEBUG
template<> base::AtomicRefCount CefCppToC<CefTranslatorTestCppToC,
    CefTranslatorTest, cef_translator_test_t>::DebugObjCt = 0;
#endif

template<> CefWrapperType CefCppToC<CefTranslatorTestCppToC, CefTranslatorTest,
    cef_translator_test_t>::kWrapperType = WT_TRANSLATOR_TEST;
