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
// $hash=7f04c8da6105e3e52b804b4c029db0e23cf41de1$
//

#include "libcef_dll/cpptoc/list_value_cpptoc.h"
#include "libcef_dll/cpptoc/binary_value_cpptoc.h"
#include "libcef_dll/cpptoc/dictionary_value_cpptoc.h"
#include "libcef_dll/cpptoc/value_cpptoc.h"
#include "libcef_dll/shutdown_checker.h"

// GLOBAL FUNCTIONS - Body may be edited by hand.

CEF_EXPORT cef_list_value_t* cef_list_value_create() {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  CefRefPtr<CefListValue> _retval = CefListValue::Create();

  // Return type: refptr_same
  return CefListValueCppToC::Wrap(_retval);
}

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

int CEF_CALLBACK list_value_is_valid(struct _cef_list_value_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefListValueCppToC::Get(self)->IsValid();

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK list_value_is_owned(struct _cef_list_value_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefListValueCppToC::Get(self)->IsOwned();

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK list_value_is_read_only(struct _cef_list_value_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefListValueCppToC::Get(self)->IsReadOnly();

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK list_value_is_same(struct _cef_list_value_t* self,
                                    struct _cef_list_value_t* that) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: that; type: refptr_same
  DCHECK(that);
  if (!that)
    return 0;

  // Execute
  bool _retval =
      CefListValueCppToC::Get(self)->IsSame(CefListValueCppToC::Unwrap(that));

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK list_value_is_equal(struct _cef_list_value_t* self,
                                     struct _cef_list_value_t* that) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: that; type: refptr_same
  DCHECK(that);
  if (!that)
    return 0;

  // Execute
  bool _retval =
      CefListValueCppToC::Get(self)->IsEqual(CefListValueCppToC::Unwrap(that));

  // Return type: bool
  return _retval;
}

struct _cef_list_value_t* CEF_CALLBACK
list_value_copy(struct _cef_list_value_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefListValue> _retval = CefListValueCppToC::Get(self)->Copy();

  // Return type: refptr_same
  return CefListValueCppToC::Wrap(_retval);
}

int CEF_CALLBACK list_value_set_size(struct _cef_list_value_t* self,
                                     size_t size) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefListValueCppToC::Get(self)->SetSize(size);

  // Return type: bool
  return _retval;
}

size_t CEF_CALLBACK list_value_get_size(struct _cef_list_value_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  size_t _retval = CefListValueCppToC::Get(self)->GetSize();

  // Return type: simple
  return _retval;
}

int CEF_CALLBACK list_value_clear(struct _cef_list_value_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefListValueCppToC::Get(self)->Clear();

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK list_value_remove(struct _cef_list_value_t* self,
                                   size_t index) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefListValueCppToC::Get(self)->Remove(index);

  // Return type: bool
  return _retval;
}

cef_value_type_t CEF_CALLBACK
list_value_get_type(struct _cef_list_value_t* self, size_t index) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return VTYPE_INVALID;

  // Execute
  cef_value_type_t _retval = CefListValueCppToC::Get(self)->GetType(index);

  // Return type: simple
  return _retval;
}

cef_value_t* CEF_CALLBACK list_value_get_value(struct _cef_list_value_t* self,
                                               size_t index) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefValue> _retval = CefListValueCppToC::Get(self)->GetValue(index);

  // Return type: refptr_same
  return CefValueCppToC::Wrap(_retval);
}

int CEF_CALLBACK list_value_get_bool(struct _cef_list_value_t* self,
                                     size_t index) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefListValueCppToC::Get(self)->GetBool(index);

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK list_value_get_int(struct _cef_list_value_t* self,
                                    size_t index) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  int _retval = CefListValueCppToC::Get(self)->GetInt(index);

  // Return type: simple
  return _retval;
}

double CEF_CALLBACK list_value_get_double(struct _cef_list_value_t* self,
                                          size_t index) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  double _retval = CefListValueCppToC::Get(self)->GetDouble(index);

  // Return type: simple
  return _retval;
}

cef_string_userfree_t CEF_CALLBACK
list_value_get_string(struct _cef_list_value_t* self, size_t index) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefListValueCppToC::Get(self)->GetString(index);

  // Return type: string
  return _retval.DetachToUserFree();
}

cef_binary_value_t* CEF_CALLBACK
list_value_get_binary(struct _cef_list_value_t* self, size_t index) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefBinaryValue> _retval =
      CefListValueCppToC::Get(self)->GetBinary(index);

  // Return type: refptr_same
  return CefBinaryValueCppToC::Wrap(_retval);
}

cef_dictionary_value_t* CEF_CALLBACK
list_value_get_dictionary(struct _cef_list_value_t* self, size_t index) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefDictionaryValue> _retval =
      CefListValueCppToC::Get(self)->GetDictionary(index);

  // Return type: refptr_same
  return CefDictionaryValueCppToC::Wrap(_retval);
}

struct _cef_list_value_t* CEF_CALLBACK
list_value_get_list(struct _cef_list_value_t* self, size_t index) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefListValue> _retval =
      CefListValueCppToC::Get(self)->GetList(index);

  // Return type: refptr_same
  return CefListValueCppToC::Wrap(_retval);
}

int CEF_CALLBACK list_value_set_value(struct _cef_list_value_t* self,
                                      size_t index,
                                      cef_value_t* value) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: value; type: refptr_same
  DCHECK(value);
  if (!value)
    return 0;

  // Execute
  bool _retval = CefListValueCppToC::Get(self)->SetValue(
      index, CefValueCppToC::Unwrap(value));

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK list_value_set_null(struct _cef_list_value_t* self,
                                     size_t index) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefListValueCppToC::Get(self)->SetNull(index);

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK list_value_set_bool(struct _cef_list_value_t* self,
                                     size_t index,
                                     int value) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval =
      CefListValueCppToC::Get(self)->SetBool(index, value ? true : false);

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK list_value_set_int(struct _cef_list_value_t* self,
                                    size_t index,
                                    int value) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefListValueCppToC::Get(self)->SetInt(index, value);

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK list_value_set_double(struct _cef_list_value_t* self,
                                       size_t index,
                                       double value) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefListValueCppToC::Get(self)->SetDouble(index, value);

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK list_value_set_string(struct _cef_list_value_t* self,
                                       size_t index,
                                       const cef_string_t* value) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Unverified params: value

  // Execute
  bool _retval =
      CefListValueCppToC::Get(self)->SetString(index, CefString(value));

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK list_value_set_binary(struct _cef_list_value_t* self,
                                       size_t index,
                                       cef_binary_value_t* value) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: value; type: refptr_same
  DCHECK(value);
  if (!value)
    return 0;

  // Execute
  bool _retval = CefListValueCppToC::Get(self)->SetBinary(
      index, CefBinaryValueCppToC::Unwrap(value));

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK list_value_set_dictionary(struct _cef_list_value_t* self,
                                           size_t index,
                                           cef_dictionary_value_t* value) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: value; type: refptr_same
  DCHECK(value);
  if (!value)
    return 0;

  // Execute
  bool _retval = CefListValueCppToC::Get(self)->SetDictionary(
      index, CefDictionaryValueCppToC::Unwrap(value));

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK list_value_set_list(struct _cef_list_value_t* self,
                                     size_t index,
                                     struct _cef_list_value_t* value) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: value; type: refptr_same
  DCHECK(value);
  if (!value)
    return 0;

  // Execute
  bool _retval = CefListValueCppToC::Get(self)->SetList(
      index, CefListValueCppToC::Unwrap(value));

  // Return type: bool
  return _retval;
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

CefListValueCppToC::CefListValueCppToC() {
  GetStruct()->is_valid = list_value_is_valid;
  GetStruct()->is_owned = list_value_is_owned;
  GetStruct()->is_read_only = list_value_is_read_only;
  GetStruct()->is_same = list_value_is_same;
  GetStruct()->is_equal = list_value_is_equal;
  GetStruct()->copy = list_value_copy;
  GetStruct()->set_size = list_value_set_size;
  GetStruct()->get_size = list_value_get_size;
  GetStruct()->clear = list_value_clear;
  GetStruct()->remove = list_value_remove;
  GetStruct()->get_type = list_value_get_type;
  GetStruct()->get_value = list_value_get_value;
  GetStruct()->get_bool = list_value_get_bool;
  GetStruct()->get_int = list_value_get_int;
  GetStruct()->get_double = list_value_get_double;
  GetStruct()->get_string = list_value_get_string;
  GetStruct()->get_binary = list_value_get_binary;
  GetStruct()->get_dictionary = list_value_get_dictionary;
  GetStruct()->get_list = list_value_get_list;
  GetStruct()->set_value = list_value_set_value;
  GetStruct()->set_null = list_value_set_null;
  GetStruct()->set_bool = list_value_set_bool;
  GetStruct()->set_int = list_value_set_int;
  GetStruct()->set_double = list_value_set_double;
  GetStruct()->set_string = list_value_set_string;
  GetStruct()->set_binary = list_value_set_binary;
  GetStruct()->set_dictionary = list_value_set_dictionary;
  GetStruct()->set_list = list_value_set_list;
}

// DESTRUCTOR - Do not edit by hand.

CefListValueCppToC::~CefListValueCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
CefRefPtr<CefListValue>
CefCppToCRefCounted<CefListValueCppToC, CefListValue, cef_list_value_t>::
    UnwrapDerived(CefWrapperType type, cef_list_value_t* s) {
  NOTREACHED() << "Unexpected class type: " << type;
  return NULL;
}

#if DCHECK_IS_ON()
template <>
base::AtomicRefCount
    CefCppToCRefCounted<CefListValueCppToC, CefListValue, cef_list_value_t>::
        DebugObjCt ATOMIC_DECLARATION;
#endif

template <>
CefWrapperType CefCppToCRefCounted<CefListValueCppToC,
                                   CefListValue,
                                   cef_list_value_t>::kWrapperType =
    WT_LIST_VALUE;
