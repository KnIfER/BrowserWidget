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

#include "libcef_dll/cpptoc/views/browser_view_cpptoc.h"
#include "libcef_dll/cpptoc/views/button_cpptoc.h"
#include "libcef_dll/cpptoc/views/panel_cpptoc.h"
#include "libcef_dll/cpptoc/views/scroll_view_cpptoc.h"
#include "libcef_dll/cpptoc/views/textfield_cpptoc.h"
#include "libcef_dll/cpptoc/views/view_cpptoc.h"
#include "libcef_dll/cpptoc/views/window_cpptoc.h"
#include "libcef_dll/ctocpp/views/textfield_delegate_ctocpp.h"
#include "libcef_dll/ctocpp/views/view_delegate_ctocpp.h"


// GLOBAL FUNCTIONS - Body may be edited by hand.

CEF_EXPORT cef_textfield_t* cef_textfield_create(
    cef_textfield_delegate_t* delegate) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Unverified params: delegate

  // Execute
  CefRefPtr<CefTextfield> _retval = CefTextfield::CreateTextfield(
      CefTextfieldDelegateCToCpp::Wrap(delegate));

  // Return type: refptr_same
  return CefTextfieldCppToC::Wrap(_retval);
}


namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

void CEF_CALLBACK textfield_set_password_input(struct _cef_textfield_t* self,
    int password_input) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefTextfieldCppToC::Get(self)->SetPasswordInput(
      password_input?true:false);
}

int CEF_CALLBACK textfield_is_password_input(struct _cef_textfield_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefTextfieldCppToC::Get(self)->IsPasswordInput();

  // Return type: bool
  return _retval;
}

void CEF_CALLBACK textfield_set_read_only(struct _cef_textfield_t* self,
    int read_only) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefTextfieldCppToC::Get(self)->SetReadOnly(
      read_only?true:false);
}

int CEF_CALLBACK textfield_is_read_only(struct _cef_textfield_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefTextfieldCppToC::Get(self)->IsReadOnly();

  // Return type: bool
  return _retval;
}

cef_string_userfree_t CEF_CALLBACK textfield_get_text(
    struct _cef_textfield_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefTextfieldCppToC::Get(self)->GetText();

  // Return type: string
  return _retval.DetachToUserFree();
}

void CEF_CALLBACK textfield_set_text(struct _cef_textfield_t* self,
    const cef_string_t* text) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: text; type: string_byref_const
  DCHECK(text);
  if (!text)
    return;

  // Execute
  CefTextfieldCppToC::Get(self)->SetText(
      CefString(text));
}

void CEF_CALLBACK textfield_append_text(struct _cef_textfield_t* self,
    const cef_string_t* text) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: text; type: string_byref_const
  DCHECK(text);
  if (!text)
    return;

  // Execute
  CefTextfieldCppToC::Get(self)->AppendText(
      CefString(text));
}

void CEF_CALLBACK textfield_insert_or_replace_text(
    struct _cef_textfield_t* self, const cef_string_t* text) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: text; type: string_byref_const
  DCHECK(text);
  if (!text)
    return;

  // Execute
  CefTextfieldCppToC::Get(self)->InsertOrReplaceText(
      CefString(text));
}

int CEF_CALLBACK textfield_has_selection(struct _cef_textfield_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefTextfieldCppToC::Get(self)->HasSelection();

  // Return type: bool
  return _retval;
}

cef_string_userfree_t CEF_CALLBACK textfield_get_selected_text(
    struct _cef_textfield_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefTextfieldCppToC::Get(self)->GetSelectedText();

  // Return type: string
  return _retval.DetachToUserFree();
}

void CEF_CALLBACK textfield_select_all(struct _cef_textfield_t* self,
    int reversed) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefTextfieldCppToC::Get(self)->SelectAll(
      reversed?true:false);
}

void CEF_CALLBACK textfield_clear_selection(struct _cef_textfield_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefTextfieldCppToC::Get(self)->ClearSelection();
}

cef_range_t CEF_CALLBACK textfield_get_selected_range(
    struct _cef_textfield_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return CefRange();

  // Execute
  cef_range_t _retval = CefTextfieldCppToC::Get(self)->GetSelectedRange();

  // Return type: simple
  return _retval;
}

void CEF_CALLBACK textfield_select_range(struct _cef_textfield_t* self,
    const cef_range_t* range) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: range; type: simple_byref_const
  DCHECK(range);
  if (!range)
    return;

  // Translate param: range; type: simple_byref_const
  CefRange rangeVal = range?*range:CefRange();

  // Execute
  CefTextfieldCppToC::Get(self)->SelectRange(
      rangeVal);
}

size_t CEF_CALLBACK textfield_get_cursor_position(
    struct _cef_textfield_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  size_t _retval = CefTextfieldCppToC::Get(self)->GetCursorPosition();

  // Return type: simple
  return _retval;
}

void CEF_CALLBACK textfield_set_text_color(struct _cef_textfield_t* self,
    cef_color_t color) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefTextfieldCppToC::Get(self)->SetTextColor(
      color);
}

cef_color_t CEF_CALLBACK textfield_get_text_color(
    struct _cef_textfield_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  cef_color_t _retval = CefTextfieldCppToC::Get(self)->GetTextColor();

  // Return type: simple
  return _retval;
}

void CEF_CALLBACK textfield_set_selection_text_color(
    struct _cef_textfield_t* self, cef_color_t color) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefTextfieldCppToC::Get(self)->SetSelectionTextColor(
      color);
}

cef_color_t CEF_CALLBACK textfield_get_selection_text_color(
    struct _cef_textfield_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  cef_color_t _retval = CefTextfieldCppToC::Get(self)->GetSelectionTextColor();

  // Return type: simple
  return _retval;
}

void CEF_CALLBACK textfield_set_selection_background_color(
    struct _cef_textfield_t* self, cef_color_t color) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefTextfieldCppToC::Get(self)->SetSelectionBackgroundColor(
      color);
}

cef_color_t CEF_CALLBACK textfield_get_selection_background_color(
    struct _cef_textfield_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  cef_color_t _retval = CefTextfieldCppToC::Get(
      self)->GetSelectionBackgroundColor();

  // Return type: simple
  return _retval;
}

void CEF_CALLBACK textfield_set_font_list(struct _cef_textfield_t* self,
    const cef_string_t* font_list) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: font_list; type: string_byref_const
  DCHECK(font_list);
  if (!font_list)
    return;

  // Execute
  CefTextfieldCppToC::Get(self)->SetFontList(
      CefString(font_list));
}

void CEF_CALLBACK textfield_apply_text_color(struct _cef_textfield_t* self,
    cef_color_t color, const cef_range_t* range) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: range; type: simple_byref_const
  DCHECK(range);
  if (!range)
    return;

  // Translate param: range; type: simple_byref_const
  CefRange rangeVal = range?*range:CefRange();

  // Execute
  CefTextfieldCppToC::Get(self)->ApplyTextColor(
      color,
      rangeVal);
}

void CEF_CALLBACK textfield_apply_text_style(struct _cef_textfield_t* self,
    cef_text_style_t style, int add, const cef_range_t* range) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: range; type: simple_byref_const
  DCHECK(range);
  if (!range)
    return;

  // Translate param: range; type: simple_byref_const
  CefRange rangeVal = range?*range:CefRange();

  // Execute
  CefTextfieldCppToC::Get(self)->ApplyTextStyle(
      style,
      add?true:false,
      rangeVal);
}

int CEF_CALLBACK textfield_is_command_enabled(struct _cef_textfield_t* self,
    int command_id) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefTextfieldCppToC::Get(self)->IsCommandEnabled(
      command_id);

  // Return type: bool
  return _retval;
}

void CEF_CALLBACK textfield_execute_command(struct _cef_textfield_t* self,
    int command_id) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefTextfieldCppToC::Get(self)->ExecuteCommand(
      command_id);
}

void CEF_CALLBACK textfield_clear_edit_history(struct _cef_textfield_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefTextfieldCppToC::Get(self)->ClearEditHistory();
}

void CEF_CALLBACK textfield_set_placeholder_text(struct _cef_textfield_t* self,
    const cef_string_t* text) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: text; type: string_byref_const
  DCHECK(text);
  if (!text)
    return;

  // Execute
  CefTextfieldCppToC::Get(self)->SetPlaceholderText(
      CefString(text));
}

cef_string_userfree_t CEF_CALLBACK textfield_get_placeholder_text(
    struct _cef_textfield_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefTextfieldCppToC::Get(self)->GetPlaceholderText();

  // Return type: string
  return _retval.DetachToUserFree();
}

void CEF_CALLBACK textfield_set_placeholder_text_color(
    struct _cef_textfield_t* self, cef_color_t color) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefTextfieldCppToC::Get(self)->SetPlaceholderTextColor(
      color);
}

void CEF_CALLBACK textfield_set_accessible_name(struct _cef_textfield_t* self,
    const cef_string_t* name) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: name; type: string_byref_const
  DCHECK(name);
  if (!name)
    return;

  // Execute
  CefTextfieldCppToC::Get(self)->SetAccessibleName(
      CefString(name));
}

cef_browser_view_t* CEF_CALLBACK textfield_as_browser_view(
    struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefBrowserView> _retval = CefTextfieldCppToC::Get(
      reinterpret_cast<cef_textfield_t*>(self))->AsBrowserView();

  // Return type: refptr_same
  return CefBrowserViewCppToC::Wrap(_retval);
}

cef_button_t* CEF_CALLBACK textfield_as_button(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefButton> _retval = CefTextfieldCppToC::Get(
      reinterpret_cast<cef_textfield_t*>(self))->AsButton();

  // Return type: refptr_same
  return CefButtonCppToC::Wrap(_retval);
}

cef_panel_t* CEF_CALLBACK textfield_as_panel(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefPanel> _retval = CefTextfieldCppToC::Get(
      reinterpret_cast<cef_textfield_t*>(self))->AsPanel();

  // Return type: refptr_same
  return CefPanelCppToC::Wrap(_retval);
}

cef_scroll_view_t* CEF_CALLBACK textfield_as_scroll_view(
    struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefScrollView> _retval = CefTextfieldCppToC::Get(
      reinterpret_cast<cef_textfield_t*>(self))->AsScrollView();

  // Return type: refptr_same
  return CefScrollViewCppToC::Wrap(_retval);
}

cef_textfield_t* CEF_CALLBACK textfield_as_textfield(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefTextfield> _retval = CefTextfieldCppToC::Get(
      reinterpret_cast<cef_textfield_t*>(self))->AsTextfield();

  // Return type: refptr_same
  return CefTextfieldCppToC::Wrap(_retval);
}

cef_string_userfree_t CEF_CALLBACK textfield_get_type_string(
    struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefTextfieldCppToC::Get(
      reinterpret_cast<cef_textfield_t*>(self))->GetTypeString();

  // Return type: string
  return _retval.DetachToUserFree();
}

cef_string_userfree_t CEF_CALLBACK textfield_to_string(struct _cef_view_t* self,
    int include_children) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefTextfieldCppToC::Get(
      reinterpret_cast<cef_textfield_t*>(self))->ToString(
      include_children?true:false);

  // Return type: string
  return _retval.DetachToUserFree();
}

int CEF_CALLBACK textfield_is_valid(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefTextfieldCppToC::Get(reinterpret_cast<cef_textfield_t*>(
      self))->IsValid();

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK textfield_is_attached(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefTextfieldCppToC::Get(reinterpret_cast<cef_textfield_t*>(
      self))->IsAttached();

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK textfield_is_same(struct _cef_view_t* self,
    struct _cef_view_t* that) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: that; type: refptr_same
  DCHECK(that);
  if (!that)
    return 0;

  // Execute
  bool _retval = CefTextfieldCppToC::Get(reinterpret_cast<cef_textfield_t*>(
      self))->IsSame(
      CefViewCppToC::Unwrap(that));

  // Return type: bool
  return _retval;
}

struct _cef_view_delegate_t* CEF_CALLBACK textfield_get_delegate(
    struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefViewDelegate> _retval = CefTextfieldCppToC::Get(
      reinterpret_cast<cef_textfield_t*>(self))->GetDelegate();

  // Return type: refptr_diff
  return CefViewDelegateCToCpp::Unwrap(_retval);
}

struct _cef_window_t* CEF_CALLBACK textfield_get_window(
    struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefWindow> _retval = CefTextfieldCppToC::Get(
      reinterpret_cast<cef_textfield_t*>(self))->GetWindow();

  // Return type: refptr_same
  return CefWindowCppToC::Wrap(_retval);
}

int CEF_CALLBACK textfield_get_id(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  int _retval = CefTextfieldCppToC::Get(reinterpret_cast<cef_textfield_t*>(
      self))->GetID();

  // Return type: simple
  return _retval;
}

void CEF_CALLBACK textfield_set_id(struct _cef_view_t* self, int id) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefTextfieldCppToC::Get(reinterpret_cast<cef_textfield_t*>(self))->SetID(
      id);
}

struct _cef_view_t* CEF_CALLBACK textfield_get_parent_view(
    struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefView> _retval = CefTextfieldCppToC::Get(
      reinterpret_cast<cef_textfield_t*>(self))->GetParentView();

  // Return type: refptr_same
  return CefViewCppToC::Wrap(_retval);
}

struct _cef_view_t* CEF_CALLBACK textfield_get_view_for_id(
    struct _cef_view_t* self, int id) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefView> _retval = CefTextfieldCppToC::Get(
      reinterpret_cast<cef_textfield_t*>(self))->GetViewForID(
      id);

  // Return type: refptr_same
  return CefViewCppToC::Wrap(_retval);
}

void CEF_CALLBACK textfield_set_bounds(struct _cef_view_t* self,
    const cef_rect_t* bounds) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: bounds; type: simple_byref_const
  DCHECK(bounds);
  if (!bounds)
    return;

  // Translate param: bounds; type: simple_byref_const
  CefRect boundsVal = bounds?*bounds:CefRect();

  // Execute
  CefTextfieldCppToC::Get(reinterpret_cast<cef_textfield_t*>(self))->SetBounds(
      boundsVal);
}

cef_rect_t CEF_CALLBACK textfield_get_bounds(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return CefRect();

  // Execute
  cef_rect_t _retval = CefTextfieldCppToC::Get(
      reinterpret_cast<cef_textfield_t*>(self))->GetBounds();

  // Return type: simple
  return _retval;
}

cef_rect_t CEF_CALLBACK textfield_get_bounds_in_screen(
    struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return CefRect();

  // Execute
  cef_rect_t _retval = CefTextfieldCppToC::Get(
      reinterpret_cast<cef_textfield_t*>(self))->GetBoundsInScreen();

  // Return type: simple
  return _retval;
}

void CEF_CALLBACK textfield_set_size(struct _cef_view_t* self,
    const cef_size_t* size) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: size; type: simple_byref_const
  DCHECK(size);
  if (!size)
    return;

  // Translate param: size; type: simple_byref_const
  CefSize sizeVal = size?*size:CefSize();

  // Execute
  CefTextfieldCppToC::Get(reinterpret_cast<cef_textfield_t*>(self))->SetSize(
      sizeVal);
}

cef_size_t CEF_CALLBACK textfield_get_size(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return CefSize();

  // Execute
  cef_size_t _retval = CefTextfieldCppToC::Get(
      reinterpret_cast<cef_textfield_t*>(self))->GetSize();

  // Return type: simple
  return _retval;
}

void CEF_CALLBACK textfield_set_position(struct _cef_view_t* self,
    const cef_point_t* position) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: position; type: simple_byref_const
  DCHECK(position);
  if (!position)
    return;

  // Translate param: position; type: simple_byref_const
  CefPoint positionVal = position?*position:CefPoint();

  // Execute
  CefTextfieldCppToC::Get(reinterpret_cast<cef_textfield_t*>(
      self))->SetPosition(
      positionVal);
}

cef_point_t CEF_CALLBACK textfield_get_position(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return CefPoint();

  // Execute
  cef_point_t _retval = CefTextfieldCppToC::Get(
      reinterpret_cast<cef_textfield_t*>(self))->GetPosition();

  // Return type: simple
  return _retval;
}

cef_size_t CEF_CALLBACK textfield_get_preferred_size(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return CefSize();

  // Execute
  cef_size_t _retval = CefTextfieldCppToC::Get(
      reinterpret_cast<cef_textfield_t*>(self))->GetPreferredSize();

  // Return type: simple
  return _retval;
}

void CEF_CALLBACK textfield_size_to_preferred_size(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefTextfieldCppToC::Get(reinterpret_cast<cef_textfield_t*>(
      self))->SizeToPreferredSize();
}

cef_size_t CEF_CALLBACK textfield_get_minimum_size(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return CefSize();

  // Execute
  cef_size_t _retval = CefTextfieldCppToC::Get(
      reinterpret_cast<cef_textfield_t*>(self))->GetMinimumSize();

  // Return type: simple
  return _retval;
}

cef_size_t CEF_CALLBACK textfield_get_maximum_size(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return CefSize();

  // Execute
  cef_size_t _retval = CefTextfieldCppToC::Get(
      reinterpret_cast<cef_textfield_t*>(self))->GetMaximumSize();

  // Return type: simple
  return _retval;
}

int CEF_CALLBACK textfield_get_height_for_width(struct _cef_view_t* self,
    int width) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  int _retval = CefTextfieldCppToC::Get(reinterpret_cast<cef_textfield_t*>(
      self))->GetHeightForWidth(
      width);

  // Return type: simple
  return _retval;
}

void CEF_CALLBACK textfield_invalidate_layout(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefTextfieldCppToC::Get(reinterpret_cast<cef_textfield_t*>(
      self))->InvalidateLayout();
}

void CEF_CALLBACK textfield_set_visible(struct _cef_view_t* self, int visible) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefTextfieldCppToC::Get(reinterpret_cast<cef_textfield_t*>(self))->SetVisible(
      visible?true:false);
}

int CEF_CALLBACK textfield_is_visible(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefTextfieldCppToC::Get(reinterpret_cast<cef_textfield_t*>(
      self))->IsVisible();

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK textfield_is_drawn(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefTextfieldCppToC::Get(reinterpret_cast<cef_textfield_t*>(
      self))->IsDrawn();

  // Return type: bool
  return _retval;
}

void CEF_CALLBACK textfield_set_enabled(struct _cef_view_t* self, int enabled) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefTextfieldCppToC::Get(reinterpret_cast<cef_textfield_t*>(self))->SetEnabled(
      enabled?true:false);
}

int CEF_CALLBACK textfield_is_enabled(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefTextfieldCppToC::Get(reinterpret_cast<cef_textfield_t*>(
      self))->IsEnabled();

  // Return type: bool
  return _retval;
}

void CEF_CALLBACK textfield_set_focusable(struct _cef_view_t* self,
    int focusable) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefTextfieldCppToC::Get(reinterpret_cast<cef_textfield_t*>(
      self))->SetFocusable(
      focusable?true:false);
}

int CEF_CALLBACK textfield_is_focusable(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefTextfieldCppToC::Get(reinterpret_cast<cef_textfield_t*>(
      self))->IsFocusable();

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK textfield_is_accessibility_focusable(
    struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefTextfieldCppToC::Get(reinterpret_cast<cef_textfield_t*>(
      self))->IsAccessibilityFocusable();

  // Return type: bool
  return _retval;
}

void CEF_CALLBACK textfield_request_focus(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefTextfieldCppToC::Get(reinterpret_cast<cef_textfield_t*>(
      self))->RequestFocus();
}

void CEF_CALLBACK textfield_set_background_color(struct _cef_view_t* self,
    cef_color_t color) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefTextfieldCppToC::Get(reinterpret_cast<cef_textfield_t*>(
      self))->SetBackgroundColor(
      color);
}

cef_color_t CEF_CALLBACK textfield_get_background_color(
    struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  cef_color_t _retval = CefTextfieldCppToC::Get(
      reinterpret_cast<cef_textfield_t*>(self))->GetBackgroundColor();

  // Return type: simple
  return _retval;
}

int CEF_CALLBACK textfield_convert_point_to_screen(struct _cef_view_t* self,
    cef_point_t* point) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: point; type: simple_byref
  DCHECK(point);
  if (!point)
    return 0;

  // Translate param: point; type: simple_byref
  CefPoint pointVal = point?*point:CefPoint();

  // Execute
  bool _retval = CefTextfieldCppToC::Get(reinterpret_cast<cef_textfield_t*>(
      self))->ConvertPointToScreen(
      pointVal);

  // Restore param: point; type: simple_byref
  if (point)
    *point = pointVal;

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK textfield_convert_point_from_screen(struct _cef_view_t* self,
    cef_point_t* point) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: point; type: simple_byref
  DCHECK(point);
  if (!point)
    return 0;

  // Translate param: point; type: simple_byref
  CefPoint pointVal = point?*point:CefPoint();

  // Execute
  bool _retval = CefTextfieldCppToC::Get(reinterpret_cast<cef_textfield_t*>(
      self))->ConvertPointFromScreen(
      pointVal);

  // Restore param: point; type: simple_byref
  if (point)
    *point = pointVal;

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK textfield_convert_point_to_window(struct _cef_view_t* self,
    cef_point_t* point) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: point; type: simple_byref
  DCHECK(point);
  if (!point)
    return 0;

  // Translate param: point; type: simple_byref
  CefPoint pointVal = point?*point:CefPoint();

  // Execute
  bool _retval = CefTextfieldCppToC::Get(reinterpret_cast<cef_textfield_t*>(
      self))->ConvertPointToWindow(
      pointVal);

  // Restore param: point; type: simple_byref
  if (point)
    *point = pointVal;

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK textfield_convert_point_from_window(struct _cef_view_t* self,
    cef_point_t* point) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: point; type: simple_byref
  DCHECK(point);
  if (!point)
    return 0;

  // Translate param: point; type: simple_byref
  CefPoint pointVal = point?*point:CefPoint();

  // Execute
  bool _retval = CefTextfieldCppToC::Get(reinterpret_cast<cef_textfield_t*>(
      self))->ConvertPointFromWindow(
      pointVal);

  // Restore param: point; type: simple_byref
  if (point)
    *point = pointVal;

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK textfield_convert_point_to_view(struct _cef_view_t* self,
    struct _cef_view_t* view, cef_point_t* point) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: view; type: refptr_same
  DCHECK(view);
  if (!view)
    return 0;
  // Verify param: point; type: simple_byref
  DCHECK(point);
  if (!point)
    return 0;

  // Translate param: point; type: simple_byref
  CefPoint pointVal = point?*point:CefPoint();

  // Execute
  bool _retval = CefTextfieldCppToC::Get(reinterpret_cast<cef_textfield_t*>(
      self))->ConvertPointToView(
      CefViewCppToC::Unwrap(view),
      pointVal);

  // Restore param: point; type: simple_byref
  if (point)
    *point = pointVal;

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK textfield_convert_point_from_view(struct _cef_view_t* self,
    struct _cef_view_t* view, cef_point_t* point) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: view; type: refptr_same
  DCHECK(view);
  if (!view)
    return 0;
  // Verify param: point; type: simple_byref
  DCHECK(point);
  if (!point)
    return 0;

  // Translate param: point; type: simple_byref
  CefPoint pointVal = point?*point:CefPoint();

  // Execute
  bool _retval = CefTextfieldCppToC::Get(reinterpret_cast<cef_textfield_t*>(
      self))->ConvertPointFromView(
      CefViewCppToC::Unwrap(view),
      pointVal);

  // Restore param: point; type: simple_byref
  if (point)
    *point = pointVal;

  // Return type: bool
  return _retval;
}

}  // namespace


// CONSTRUCTOR - Do not edit by hand.

CefTextfieldCppToC::CefTextfieldCppToC() {
  GetStruct()->set_password_input = textfield_set_password_input;
  GetStruct()->is_password_input = textfield_is_password_input;
  GetStruct()->set_read_only = textfield_set_read_only;
  GetStruct()->is_read_only = textfield_is_read_only;
  GetStruct()->get_text = textfield_get_text;
  GetStruct()->set_text = textfield_set_text;
  GetStruct()->append_text = textfield_append_text;
  GetStruct()->insert_or_replace_text = textfield_insert_or_replace_text;
  GetStruct()->has_selection = textfield_has_selection;
  GetStruct()->get_selected_text = textfield_get_selected_text;
  GetStruct()->select_all = textfield_select_all;
  GetStruct()->clear_selection = textfield_clear_selection;
  GetStruct()->get_selected_range = textfield_get_selected_range;
  GetStruct()->select_range = textfield_select_range;
  GetStruct()->get_cursor_position = textfield_get_cursor_position;
  GetStruct()->set_text_color = textfield_set_text_color;
  GetStruct()->get_text_color = textfield_get_text_color;
  GetStruct()->set_selection_text_color = textfield_set_selection_text_color;
  GetStruct()->get_selection_text_color = textfield_get_selection_text_color;
  GetStruct()->set_selection_background_color =
      textfield_set_selection_background_color;
  GetStruct()->get_selection_background_color =
      textfield_get_selection_background_color;
  GetStruct()->set_font_list = textfield_set_font_list;
  GetStruct()->apply_text_color = textfield_apply_text_color;
  GetStruct()->apply_text_style = textfield_apply_text_style;
  GetStruct()->is_command_enabled = textfield_is_command_enabled;
  GetStruct()->execute_command = textfield_execute_command;
  GetStruct()->clear_edit_history = textfield_clear_edit_history;
  GetStruct()->set_placeholder_text = textfield_set_placeholder_text;
  GetStruct()->get_placeholder_text = textfield_get_placeholder_text;
  GetStruct()->set_placeholder_text_color =
      textfield_set_placeholder_text_color;
  GetStruct()->set_accessible_name = textfield_set_accessible_name;
  GetStruct()->base.as_browser_view = textfield_as_browser_view;
  GetStruct()->base.as_button = textfield_as_button;
  GetStruct()->base.as_panel = textfield_as_panel;
  GetStruct()->base.as_scroll_view = textfield_as_scroll_view;
  GetStruct()->base.as_textfield = textfield_as_textfield;
  GetStruct()->base.get_type_string = textfield_get_type_string;
  GetStruct()->base.to_string = textfield_to_string;
  GetStruct()->base.is_valid = textfield_is_valid;
  GetStruct()->base.is_attached = textfield_is_attached;
  GetStruct()->base.is_same = textfield_is_same;
  GetStruct()->base.get_delegate = textfield_get_delegate;
  GetStruct()->base.get_window = textfield_get_window;
  GetStruct()->base.get_id = textfield_get_id;
  GetStruct()->base.set_id = textfield_set_id;
  GetStruct()->base.get_parent_view = textfield_get_parent_view;
  GetStruct()->base.get_view_for_id = textfield_get_view_for_id;
  GetStruct()->base.set_bounds = textfield_set_bounds;
  GetStruct()->base.get_bounds = textfield_get_bounds;
  GetStruct()->base.get_bounds_in_screen = textfield_get_bounds_in_screen;
  GetStruct()->base.set_size = textfield_set_size;
  GetStruct()->base.get_size = textfield_get_size;
  GetStruct()->base.set_position = textfield_set_position;
  GetStruct()->base.get_position = textfield_get_position;
  GetStruct()->base.get_preferred_size = textfield_get_preferred_size;
  GetStruct()->base.size_to_preferred_size = textfield_size_to_preferred_size;
  GetStruct()->base.get_minimum_size = textfield_get_minimum_size;
  GetStruct()->base.get_maximum_size = textfield_get_maximum_size;
  GetStruct()->base.get_height_for_width = textfield_get_height_for_width;
  GetStruct()->base.invalidate_layout = textfield_invalidate_layout;
  GetStruct()->base.set_visible = textfield_set_visible;
  GetStruct()->base.is_visible = textfield_is_visible;
  GetStruct()->base.is_drawn = textfield_is_drawn;
  GetStruct()->base.set_enabled = textfield_set_enabled;
  GetStruct()->base.is_enabled = textfield_is_enabled;
  GetStruct()->base.set_focusable = textfield_set_focusable;
  GetStruct()->base.is_focusable = textfield_is_focusable;
  GetStruct()->base.is_accessibility_focusable =
      textfield_is_accessibility_focusable;
  GetStruct()->base.request_focus = textfield_request_focus;
  GetStruct()->base.set_background_color = textfield_set_background_color;
  GetStruct()->base.get_background_color = textfield_get_background_color;
  GetStruct()->base.convert_point_to_screen = textfield_convert_point_to_screen;
  GetStruct()->base.convert_point_from_screen =
      textfield_convert_point_from_screen;
  GetStruct()->base.convert_point_to_window = textfield_convert_point_to_window;
  GetStruct()->base.convert_point_from_window =
      textfield_convert_point_from_window;
  GetStruct()->base.convert_point_to_view = textfield_convert_point_to_view;
  GetStruct()->base.convert_point_from_view = textfield_convert_point_from_view;
}

template<> CefRefPtr<CefTextfield> CefCppToC<CefTextfieldCppToC, CefTextfield,
    cef_textfield_t>::UnwrapDerived(CefWrapperType type, cef_textfield_t* s) {
  NOTREACHED() << "Unexpected class type: " << type;
  return NULL;
}

#if DCHECK_IS_ON()
template<> base::AtomicRefCount CefCppToC<CefTextfieldCppToC, CefTextfield,
    cef_textfield_t>::DebugObjCt = 0;
#endif

template<> CefWrapperType CefCppToC<CefTextfieldCppToC, CefTextfield,
    cef_textfield_t>::kWrapperType = WT_TEXTFIELD;
