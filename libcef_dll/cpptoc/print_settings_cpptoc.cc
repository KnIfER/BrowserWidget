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

#include <algorithm>
#include "libcef_dll/cpptoc/print_settings_cpptoc.h"


// GLOBAL FUNCTIONS - Body may be edited by hand.

CEF_EXPORT cef_print_settings_t* cef_print_settings_create() {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  CefRefPtr<CefPrintSettings> _retval = CefPrintSettings::Create();

  // Return type: refptr_same
  return CefPrintSettingsCppToC::Wrap(_retval);
}


namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

int CEF_CALLBACK print_settings_is_valid(struct _cef_print_settings_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefPrintSettingsCppToC::Get(self)->IsValid();

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK print_settings_is_read_only(
    struct _cef_print_settings_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefPrintSettingsCppToC::Get(self)->IsReadOnly();

  // Return type: bool
  return _retval;
}

struct _cef_print_settings_t* CEF_CALLBACK print_settings_copy(
    struct _cef_print_settings_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefPrintSettings> _retval = CefPrintSettingsCppToC::Get(self)->Copy(
      );

  // Return type: refptr_same
  return CefPrintSettingsCppToC::Wrap(_retval);
}

void CEF_CALLBACK print_settings_set_orientation(
    struct _cef_print_settings_t* self, int landscape) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefPrintSettingsCppToC::Get(self)->SetOrientation(
      landscape?true:false);
}

int CEF_CALLBACK print_settings_is_landscape(
    struct _cef_print_settings_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefPrintSettingsCppToC::Get(self)->IsLandscape();

  // Return type: bool
  return _retval;
}

void CEF_CALLBACK print_settings_set_printer_printable_area(
    struct _cef_print_settings_t* self,
    const cef_size_t* physical_size_device_units,
    const cef_rect_t* printable_area_device_units, int landscape_needs_flip) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: physical_size_device_units; type: simple_byref_const
  DCHECK(physical_size_device_units);
  if (!physical_size_device_units)
    return;
  // Verify param: printable_area_device_units; type: simple_byref_const
  DCHECK(printable_area_device_units);
  if (!printable_area_device_units)
    return;

  // Translate param: physical_size_device_units; type: simple_byref_const
  CefSize physical_size_device_unitsVal =
      physical_size_device_units?*physical_size_device_units:CefSize();
  // Translate param: printable_area_device_units; type: simple_byref_const
  CefRect printable_area_device_unitsVal =
      printable_area_device_units?*printable_area_device_units:CefRect();

  // Execute
  CefPrintSettingsCppToC::Get(self)->SetPrinterPrintableArea(
      physical_size_device_unitsVal,
      printable_area_device_unitsVal,
      landscape_needs_flip?true:false);
}

void CEF_CALLBACK print_settings_set_device_name(
    struct _cef_print_settings_t* self, const cef_string_t* name) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Unverified params: name

  // Execute
  CefPrintSettingsCppToC::Get(self)->SetDeviceName(
      CefString(name));
}

cef_string_userfree_t CEF_CALLBACK print_settings_get_device_name(
    struct _cef_print_settings_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefPrintSettingsCppToC::Get(self)->GetDeviceName();

  // Return type: string
  return _retval.DetachToUserFree();
}

void CEF_CALLBACK print_settings_set_dpi(struct _cef_print_settings_t* self,
    int dpi) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefPrintSettingsCppToC::Get(self)->SetDPI(
      dpi);
}

int CEF_CALLBACK print_settings_get_dpi(struct _cef_print_settings_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  int _retval = CefPrintSettingsCppToC::Get(self)->GetDPI();

  // Return type: simple
  return _retval;
}

void CEF_CALLBACK print_settings_set_page_ranges(
    struct _cef_print_settings_t* self, size_t rangesCount,
    cef_range_t const* ranges) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: ranges; type: simple_vec_byref_const
  DCHECK(rangesCount == 0 || ranges);
  if (rangesCount > 0 && !ranges)
    return;

  // Translate param: ranges; type: simple_vec_byref_const
  std::vector<CefRange > rangesList;
  if (rangesCount > 0) {
    for (size_t i = 0; i < rangesCount; ++i) {
      CefRange rangesVal = ranges[i];
      rangesList.push_back(rangesVal);
    }
  }

  // Execute
  CefPrintSettingsCppToC::Get(self)->SetPageRanges(
      rangesList);
}

size_t CEF_CALLBACK print_settings_get_page_ranges_count(
    struct _cef_print_settings_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  size_t _retval = CefPrintSettingsCppToC::Get(self)->GetPageRangesCount();

  // Return type: simple
  return _retval;
}

void CEF_CALLBACK print_settings_get_page_ranges(
    struct _cef_print_settings_t* self, size_t* rangesCount,
    cef_range_t* ranges) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: ranges; type: simple_vec_byref
  DCHECK(rangesCount && (*rangesCount == 0 || ranges));
  if (!rangesCount || (*rangesCount > 0 && !ranges))
    return;

  // Translate param: ranges; type: simple_vec_byref
  std::vector<CefRange > rangesList;
  if (rangesCount && *rangesCount > 0 && ranges) {
    for (size_t i = 0; i < *rangesCount; ++i) {
      rangesList.push_back(ranges[i]);
    }
  }

  // Execute
  CefPrintSettingsCppToC::Get(self)->GetPageRanges(
      rangesList);

  // Restore param: ranges; type: simple_vec_byref
  if (rangesCount && ranges) {
    *rangesCount = std::min(rangesList.size(), *rangesCount);
    if (*rangesCount > 0) {
      for (size_t i = 0; i < *rangesCount; ++i) {
        ranges[i] = rangesList[i];
      }
    }
  }
}

void CEF_CALLBACK print_settings_set_selection_only(
    struct _cef_print_settings_t* self, int selection_only) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefPrintSettingsCppToC::Get(self)->SetSelectionOnly(
      selection_only?true:false);
}

int CEF_CALLBACK print_settings_is_selection_only(
    struct _cef_print_settings_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefPrintSettingsCppToC::Get(self)->IsSelectionOnly();

  // Return type: bool
  return _retval;
}

void CEF_CALLBACK print_settings_set_collate(struct _cef_print_settings_t* self,
    int collate) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefPrintSettingsCppToC::Get(self)->SetCollate(
      collate?true:false);
}

int CEF_CALLBACK print_settings_will_collate(
    struct _cef_print_settings_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefPrintSettingsCppToC::Get(self)->WillCollate();

  // Return type: bool
  return _retval;
}

void CEF_CALLBACK print_settings_set_color_model(
    struct _cef_print_settings_t* self, cef_color_model_t model) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefPrintSettingsCppToC::Get(self)->SetColorModel(
      model);
}

cef_color_model_t CEF_CALLBACK print_settings_get_color_model(
    struct _cef_print_settings_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return COLOR_MODEL_UNKNOWN;

  // Execute
  cef_color_model_t _retval = CefPrintSettingsCppToC::Get(self)->GetColorModel(
      );

  // Return type: simple
  return _retval;
}

void CEF_CALLBACK print_settings_set_copies(struct _cef_print_settings_t* self,
    int copies) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefPrintSettingsCppToC::Get(self)->SetCopies(
      copies);
}

int CEF_CALLBACK print_settings_get_copies(struct _cef_print_settings_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  int _retval = CefPrintSettingsCppToC::Get(self)->GetCopies();

  // Return type: simple
  return _retval;
}

void CEF_CALLBACK print_settings_set_duplex_mode(
    struct _cef_print_settings_t* self, cef_duplex_mode_t mode) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefPrintSettingsCppToC::Get(self)->SetDuplexMode(
      mode);
}

cef_duplex_mode_t CEF_CALLBACK print_settings_get_duplex_mode(
    struct _cef_print_settings_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return DUPLEX_MODE_UNKNOWN;

  // Execute
  cef_duplex_mode_t _retval = CefPrintSettingsCppToC::Get(self)->GetDuplexMode(
      );

  // Return type: simple
  return _retval;
}

}  // namespace


// CONSTRUCTOR - Do not edit by hand.

CefPrintSettingsCppToC::CefPrintSettingsCppToC() {
  GetStruct()->is_valid = print_settings_is_valid;
  GetStruct()->is_read_only = print_settings_is_read_only;
  GetStruct()->copy = print_settings_copy;
  GetStruct()->set_orientation = print_settings_set_orientation;
  GetStruct()->is_landscape = print_settings_is_landscape;
  GetStruct()->set_printer_printable_area =
      print_settings_set_printer_printable_area;
  GetStruct()->set_device_name = print_settings_set_device_name;
  GetStruct()->get_device_name = print_settings_get_device_name;
  GetStruct()->set_dpi = print_settings_set_dpi;
  GetStruct()->get_dpi = print_settings_get_dpi;
  GetStruct()->set_page_ranges = print_settings_set_page_ranges;
  GetStruct()->get_page_ranges_count = print_settings_get_page_ranges_count;
  GetStruct()->get_page_ranges = print_settings_get_page_ranges;
  GetStruct()->set_selection_only = print_settings_set_selection_only;
  GetStruct()->is_selection_only = print_settings_is_selection_only;
  GetStruct()->set_collate = print_settings_set_collate;
  GetStruct()->will_collate = print_settings_will_collate;
  GetStruct()->set_color_model = print_settings_set_color_model;
  GetStruct()->get_color_model = print_settings_get_color_model;
  GetStruct()->set_copies = print_settings_set_copies;
  GetStruct()->get_copies = print_settings_get_copies;
  GetStruct()->set_duplex_mode = print_settings_set_duplex_mode;
  GetStruct()->get_duplex_mode = print_settings_get_duplex_mode;
}

template<> CefRefPtr<CefPrintSettings> CefCppToC<CefPrintSettingsCppToC,
    CefPrintSettings, cef_print_settings_t>::UnwrapDerived(CefWrapperType type,
    cef_print_settings_t* s) {
  NOTREACHED() << "Unexpected class type: " << type;
  return NULL;
}

#ifndef NDEBUG
template<> base::AtomicRefCount CefCppToC<CefPrintSettingsCppToC,
    CefPrintSettings, cef_print_settings_t>::DebugObjCt = 0;
#endif

template<> CefWrapperType CefCppToC<CefPrintSettingsCppToC, CefPrintSettings,
    cef_print_settings_t>::kWrapperType = WT_PRINT_SETTINGS;
