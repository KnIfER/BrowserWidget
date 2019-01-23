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
// $hash=17672463eca45a4bd4e95f559ac205889047b2bf$
//

#include "libcef_dll/ctocpp/views/menu_button_delegate_ctocpp.h"
#include "libcef_dll/cpptoc/views/button_cpptoc.h"
#include "libcef_dll/cpptoc/views/menu_button_cpptoc.h"
#include "libcef_dll/cpptoc/views/menu_button_pressed_lock_cpptoc.h"
#include "libcef_dll/cpptoc/views/view_cpptoc.h"
#include "libcef_dll/shutdown_checker.h"

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
void CefMenuButtonDelegateCToCpp::OnMenuButtonPressed(
    CefRefPtr<CefMenuButton> menu_button,
    const CefPoint& screen_point,
    CefRefPtr<CefMenuButtonPressedLock> button_pressed_lock) {
  shutdown_checker::AssertNotShutdown();

  cef_menu_button_delegate_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, on_menu_button_pressed))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: menu_button; type: refptr_diff
  DCHECK(menu_button.get());
  if (!menu_button.get())
    return;
  // Verify param: button_pressed_lock; type: refptr_diff
  DCHECK(button_pressed_lock.get());
  if (!button_pressed_lock.get())
    return;

  // Execute
  _struct->on_menu_button_pressed(
      _struct, CefMenuButtonCppToC::Wrap(menu_button), &screen_point,
      CefMenuButtonPressedLockCppToC::Wrap(button_pressed_lock));
}

NO_SANITIZE("cfi-icall")
void CefMenuButtonDelegateCToCpp::OnButtonPressed(CefRefPtr<CefButton> button) {
  shutdown_checker::AssertNotShutdown();

  cef_button_delegate_t* _struct =
      reinterpret_cast<cef_button_delegate_t*>(GetStruct());
  if (CEF_MEMBER_MISSING(_struct, on_button_pressed))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: button; type: refptr_diff
  DCHECK(button.get());
  if (!button.get())
    return;

  // Execute
  _struct->on_button_pressed(_struct, CefButtonCppToC::Wrap(button));
}

NO_SANITIZE("cfi-icall")
void CefMenuButtonDelegateCToCpp::OnButtonStateChanged(
    CefRefPtr<CefButton> button) {
  shutdown_checker::AssertNotShutdown();

  cef_button_delegate_t* _struct =
      reinterpret_cast<cef_button_delegate_t*>(GetStruct());
  if (CEF_MEMBER_MISSING(_struct, on_button_state_changed))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: button; type: refptr_diff
  DCHECK(button.get());
  if (!button.get())
    return;

  // Execute
  _struct->on_button_state_changed(_struct, CefButtonCppToC::Wrap(button));
}

NO_SANITIZE("cfi-icall")
CefSize CefMenuButtonDelegateCToCpp::GetPreferredSize(CefRefPtr<CefView> view) {
  shutdown_checker::AssertNotShutdown();

  cef_view_delegate_t* _struct =
      reinterpret_cast<cef_view_delegate_t*>(GetStruct());
  if (CEF_MEMBER_MISSING(_struct, get_preferred_size))
    return CefSize();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: view; type: refptr_diff
  DCHECK(view.get());
  if (!view.get())
    return CefSize();

  // Execute
  cef_size_t _retval =
      _struct->get_preferred_size(_struct, CefViewCppToC::Wrap(view));

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
CefSize CefMenuButtonDelegateCToCpp::GetMinimumSize(CefRefPtr<CefView> view) {
  shutdown_checker::AssertNotShutdown();

  cef_view_delegate_t* _struct =
      reinterpret_cast<cef_view_delegate_t*>(GetStruct());
  if (CEF_MEMBER_MISSING(_struct, get_minimum_size))
    return CefSize();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: view; type: refptr_diff
  DCHECK(view.get());
  if (!view.get())
    return CefSize();

  // Execute
  cef_size_t _retval =
      _struct->get_minimum_size(_struct, CefViewCppToC::Wrap(view));

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
CefSize CefMenuButtonDelegateCToCpp::GetMaximumSize(CefRefPtr<CefView> view) {
  shutdown_checker::AssertNotShutdown();

  cef_view_delegate_t* _struct =
      reinterpret_cast<cef_view_delegate_t*>(GetStruct());
  if (CEF_MEMBER_MISSING(_struct, get_maximum_size))
    return CefSize();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: view; type: refptr_diff
  DCHECK(view.get());
  if (!view.get())
    return CefSize();

  // Execute
  cef_size_t _retval =
      _struct->get_maximum_size(_struct, CefViewCppToC::Wrap(view));

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
int CefMenuButtonDelegateCToCpp::GetHeightForWidth(CefRefPtr<CefView> view,
                                                   int width) {
  shutdown_checker::AssertNotShutdown();

  cef_view_delegate_t* _struct =
      reinterpret_cast<cef_view_delegate_t*>(GetStruct());
  if (CEF_MEMBER_MISSING(_struct, get_height_for_width))
    return 0;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: view; type: refptr_diff
  DCHECK(view.get());
  if (!view.get())
    return 0;

  // Execute
  int _retval =
      _struct->get_height_for_width(_struct, CefViewCppToC::Wrap(view), width);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
void CefMenuButtonDelegateCToCpp::OnParentViewChanged(
    CefRefPtr<CefView> view,
    bool added,
    CefRefPtr<CefView> parent) {
  shutdown_checker::AssertNotShutdown();

  cef_view_delegate_t* _struct =
      reinterpret_cast<cef_view_delegate_t*>(GetStruct());
  if (CEF_MEMBER_MISSING(_struct, on_parent_view_changed))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: view; type: refptr_diff
  DCHECK(view.get());
  if (!view.get())
    return;
  // Verify param: parent; type: refptr_diff
  DCHECK(parent.get());
  if (!parent.get())
    return;

  // Execute
  _struct->on_parent_view_changed(_struct, CefViewCppToC::Wrap(view), added,
                                  CefViewCppToC::Wrap(parent));
}

NO_SANITIZE("cfi-icall")
void CefMenuButtonDelegateCToCpp::OnChildViewChanged(CefRefPtr<CefView> view,
                                                     bool added,
                                                     CefRefPtr<CefView> child) {
  shutdown_checker::AssertNotShutdown();

  cef_view_delegate_t* _struct =
      reinterpret_cast<cef_view_delegate_t*>(GetStruct());
  if (CEF_MEMBER_MISSING(_struct, on_child_view_changed))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: view; type: refptr_diff
  DCHECK(view.get());
  if (!view.get())
    return;
  // Verify param: child; type: refptr_diff
  DCHECK(child.get());
  if (!child.get())
    return;

  // Execute
  _struct->on_child_view_changed(_struct, CefViewCppToC::Wrap(view), added,
                                 CefViewCppToC::Wrap(child));
}

NO_SANITIZE("cfi-icall")
void CefMenuButtonDelegateCToCpp::OnFocus(CefRefPtr<CefView> view) {
  shutdown_checker::AssertNotShutdown();

  cef_view_delegate_t* _struct =
      reinterpret_cast<cef_view_delegate_t*>(GetStruct());
  if (CEF_MEMBER_MISSING(_struct, on_focus))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: view; type: refptr_diff
  DCHECK(view.get());
  if (!view.get())
    return;

  // Execute
  _struct->on_focus(_struct, CefViewCppToC::Wrap(view));
}

NO_SANITIZE("cfi-icall")
void CefMenuButtonDelegateCToCpp::OnBlur(CefRefPtr<CefView> view) {
  shutdown_checker::AssertNotShutdown();

  cef_view_delegate_t* _struct =
      reinterpret_cast<cef_view_delegate_t*>(GetStruct());
  if (CEF_MEMBER_MISSING(_struct, on_blur))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: view; type: refptr_diff
  DCHECK(view.get());
  if (!view.get())
    return;

  // Execute
  _struct->on_blur(_struct, CefViewCppToC::Wrap(view));
}

// CONSTRUCTOR - Do not edit by hand.

CefMenuButtonDelegateCToCpp::CefMenuButtonDelegateCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

CefMenuButtonDelegateCToCpp::~CefMenuButtonDelegateCToCpp() {
  shutdown_checker::AssertNotShutdown();
}

template <>
cef_menu_button_delegate_t* CefCToCppRefCounted<
    CefMenuButtonDelegateCToCpp,
    CefMenuButtonDelegate,
    cef_menu_button_delegate_t>::UnwrapDerived(CefWrapperType type,
                                               CefMenuButtonDelegate* c) {
  NOTREACHED() << "Unexpected class type: " << type;
  return NULL;
}

template <>
CefWrapperType CefCToCppRefCounted<CefMenuButtonDelegateCToCpp,
                                   CefMenuButtonDelegate,
                                   cef_menu_button_delegate_t>::kWrapperType =
    WT_MENU_BUTTON_DELEGATE;
