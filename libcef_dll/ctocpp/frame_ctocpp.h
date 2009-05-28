// Copyright (c) 2009 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#ifndef _FRAME_CTOCPP_H
#define _FRAME_CTOCPP_H

#ifndef USING_CEF_SHARED
#pragma message("Warning: "__FILE__" may be accessed wrapper-side only")
#else // USING_CEF_SHARED

#include "cef.h"
#include "cef_capi.h"
#include "ctocpp.h"


// Wrap a C frame structure with a C++ frame class.
// This class may be instantiated and accessed wrapper-side only.
class CefFrameCToCpp : public CefCToCpp<CefFrameCToCpp, CefFrame, cef_frame_t>
{
public:
  CefFrameCToCpp(cef_frame_t* str)
    : CefCToCpp<CefFrameCToCpp, CefFrame, cef_frame_t>(str) {}
  virtual ~CefFrameCToCpp() {}

  // CefFrame methods
  virtual void Undo();
  virtual void Redo();
  virtual void Cut();
  virtual void Copy();
  virtual void Paste();
  virtual void Delete();
  virtual void SelectAll();
  virtual void Print();
  virtual void ViewSource();
  virtual std::wstring GetSource();
  virtual std::wstring GetText();
  virtual void LoadRequest(CefRefPtr<CefRequest> request);
  virtual void LoadURL(const std::wstring& url);
  virtual void LoadString(const std::wstring& string,
                          const std::wstring& url);
  virtual void LoadStream(CefRefPtr<CefStreamReader> stream,
                          const std::wstring& url);
  virtual void ExecuteJavaScript(const std::wstring& jsCode, 
                                 const std::wstring& scriptUrl,
                                 int startLine);
  virtual bool IsMain();
  virtual bool IsFocused();
  virtual std::wstring GetName();
  virtual std::wstring GetURL();
};


#endif // USING_CEF_SHARED
#endif // _FRAME_CTOCPP_H
