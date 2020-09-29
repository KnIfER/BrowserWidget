// Copyright (c) 2015 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#include "tests/cefclient/browser/client_handler_std.h"

namespace client {


ClientHandlerStd::ClientHandlerStd(Delegate* delegate, const std::string& startup_url) 
						: ClientHandler(delegate, false, startup_url) {}

void ClientHandlerStd::OnAfterCreated(CefRefPtr<CefBrowser> browser) {
	ClientHandler::OnAfterCreated(browser);
	//TCHAR buffer[100]={0};
	//wsprintf(buffer,TEXT("OnAfterCreated=%d"), this);
	//::MessageBox(NULL, buffer, TEXT(""), MB_OK);
	_browser = browser.get();
	//if(!isRoot && !agent)
	{
		//::MessageBox(NULL, TEXT("OnAfterCreated1"), TEXT(""), MB_OK);
		//HWND hwnd = browser->GetHost()->GetWindowHandle();
		//SetWindowLongPtr(hwnd, GWLP_WNDPROC, (LONG_PTR)wWindowProc);
		//auto OldProc = (WNDPROC)GetWindowLongPtr(hwnd, GWLP_WNDPROC);
		//auto newProc = new WNDCALL{OldProc};
		//WNDPROC* proc = (WNDPROC*)newProc;
		//proc+=1;
		//SetWindowLongPtr(hwnd, GWLP_WNDPROC, (LONG_PTR)*proc);
	}
}




















}  // namespace client
