// Copyright (c) 2015 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#include <windows.h>

#include "include/base/cef_scoped_ptr.h"
#include "include/cef_command_line.h"
#include "include/cef_sandbox_win.h"
#include "tests/cefclient/browser/main_context_impl.h"
#include "tests/cefclient/browser/main_message_loop_multithreaded_win.h"
#include "tests/cefclient/browser/root_window_manager.h"
#include "tests/cefclient/browser/test_runner.h"

#include "tests/shared/browser/client_app_browser.h"
#include "tests/shared/browser/main_message_loop_external_pump.h"
#include "tests/shared/browser/main_message_loop_std.h"
#include "tests/shared/common/client_app_other.h"
#include "tests/shared/common/client_switches.h"
#include "tests/shared/renderer/client_app_renderer.h"

#include "tests\cefclient\browser\client_handler.h"
#include "tests\cefclient\browser\client_handler_std.h"

// When generating projects with CMake the CEF_USE_SANDBOX value will be defined
// automatically if using the required compiler version. Pass -DUSE_SANDBOX=OFF
// to the CMake command-line to disable use of the sandbox.
// Uncomment this line to manually enable sandbox support.
// #define CEF_USE_SANDBOX 1

extern  HINSTANCE g_hInstance;

#undef CEF_USE_SANDBOX 

#if defined(CEF_USE_SANDBOX)
// The cef_sandbox.lib static library may not link successfully with all VS
// versions.
#pragma comment(lib, "cef_sandbox.lib")
#endif

HACCEL hAccelTable;

HINSTANCE g_hInstance;

namespace client {
namespace {

int RunMain(HINSTANCE hInstance, int nCmdShow) {
  // Enable High-DPI support on Windows 7 or newer.
  CefEnableHighDPISupport();

  g_hInstance=hInstance;

  CefMainArgs main_args(hInstance);

  void* sandbox_info = nullptr;
  // Parse command-line arguments.
  CefRefPtr<CefCommandLine> command_line = CefCommandLine::CreateCommandLine();
  command_line->AppendSwitch("no-proxy-server");

  // Create a ClientApp of the correct type.
  CefRefPtr<ClientApp> app = new ClientAppBrowser();

  auto cmd = GetCommandLine();
  auto idx=wcsstr(cmd, L"\" --");
  if(idx)
  {
	  idx=idx+1;
  }
  else
  {
	  // todo boundary check
	  idx = cmd+lstrlen(cmd);
  }
  if(idx)
  {
	  lstrcpy(idx, TEXT(" -single-process -no-proxy-server -disable-logging"));
  }

  // Execute the secondary process, if any.
  int exit_code = CefExecuteProcess(main_args, app, sandbox_info);
  if (exit_code >= 0)
    return exit_code;

  // Create the main context object.
  scoped_ptr<MainContextImpl> context(new MainContextImpl(command_line, true));

  CefSettings settings;
  settings.Set({}, 0);
  CefString(&settings.application_client_id_for_file_scanning).FromString("9A8DE24D-B822-4C6C-8259-5A848FEA1E68");
  context->PopulateSettings(&settings);
  settings.command_line_args_disabled=0;
  settings.no_sandbox = true;
  settings.log_severity=LOGSEVERITY_DISABLE;

  settings.multi_threaded_message_loop=1;
  scoped_ptr<MainMessageLoopMultithreadedWin> lopper;
  lopper.reset(new MainMessageLoopMultithreadedWin);

  // Initialize CEF.
  context->Initialize(main_args, settings, app, sandbox_info);
  
  RootWindowConfig window_config;
  window_config.always_on_top = false;
  window_config.with_controls = true;
  window_config.with_osr = false; 

  // Create the first window.
  auto Browser = context->GetRootWindowManager()->CreateRootWindow(window_config);
  //Browser->GetBrowser()->

  lopper->agent=true;
  int result = lopper->Run();
  Browser->Close(true);
  //context->Shutdown();
  lopper.reset();
  context.reset();
  return result;
}

#include "tests/cefclient/browser/resource.h"


LRESULT WINAPI testWindowProc(
	__in HWND hWnd,
	__in UINT msg,
	__in WPARAM wParam,
	__in LPARAM lParam)
{
	LRESULT result = 0;
	//mbWebView view = (mbWebView)::GetProp(hWnd, L"mb");
	//if (!view)
	//	return ::DefWindowProc(hWnd, msg, wParam, lParam);

	switch (msg) { 

	case WM_ERASEBKGND:
		return TRUE;

	case WM_PAINT:
	{
		return 1;
		break;
	}
	case WM_SIZE:
	{
		return 0;
	}
	case WM_KEYDOWN:
	{
		break;
	}
	case WM_KEYUP:
	{
		break;
	}
	case WM_CHAR:
	{
		break;
	}
	case WM_LBUTTONDOWN:
	case WM_MBUTTONDOWN:
	case WM_RBUTTONDOWN:
	case WM_LBUTTONDBLCLK:
	case WM_MBUTTONDBLCLK:
	case WM_RBUTTONDBLCLK:
	case WM_LBUTTONUP:
	case WM_MBUTTONUP:
	case WM_RBUTTONUP:
	case WM_MOUSEMOVE:
	{
		break;
	}
	case WM_CONTEXTMENU:
	{

		break;
	}
	case WM_MOUSEWHEEL:
	{
		break;
	}
	case WM_SETFOCUS:
		return 0;

	case WM_KILLFOCUS:
		return 0;

	case WM_SETCURSOR:
		break;

	case WM_IME_STARTCOMPOSITION: {
		break;
	}
	}
	return ::DefWindowProc(hWnd, msg, wParam, lParam);
}




BOOL regWndClass(LPCTSTR lpcsClassName, DWORD dwStyle)
{
	WNDCLASS wndclass = { 0 };

	wndclass.style = dwStyle;
	wndclass.lpfnWndProc = testWindowProc;
	wndclass.cbClsExtra = 200;
	wndclass.cbWndExtra = 200;
	wndclass.hInstance = g_hInstance;
	wndclass.hIcon = NULL;
	//wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = lpcsClassName;

	::RegisterClass(&wndclass);
	return TRUE;
}

int MainRun(HINSTANCE hInstance, int nCmdShow) {
  // Enable High-DPI support on Windows 7 or newer.
  CefEnableHighDPISupport();

  CefMainArgs main_args(hInstance);

  void* sandbox_info = nullptr;

#if defined(CEF_USE_SANDBOX)
  // Manage the life span of the sandbox information object. This is necessary
  // for sandbox support on Windows. See cef_sandbox_win.h for complete details.
  CefScopedSandboxInfo scoped_sandbox;
  sandbox_info = scoped_sandbox.sandbox_info();
#endif

  // Parse command-line arguments.
  CefRefPtr<CefCommandLine> command_line = CefCommandLine::CreateCommandLine();
  command_line->AppendSwitch("no-proxy-server");//加载慢，关闭代理试试
  command_line->AppendSwitch("-log_severity=disable");//加载慢，关闭代理试试


  CefRefPtr<CefApp> app = new ClientAppBrowser();

  // Execute the secondary process, if any.
  int exit_code = CefExecuteProcess(main_args, app, sandbox_info);
  if (exit_code >= 0)
    return exit_code;

  // Create the main context object.
  scoped_ptr<MainContextImpl> context(new MainContextImpl(command_line, true));

  CefSettings settings;

  settings.no_sandbox = true;
  // Applications should specify a unique GUID here to enable trusted downloads.
  CefString(&settings.application_client_id_for_file_scanning).FromString("9A8DE24D-B822-4C6C-8259-5A848FEA1E68");

  // Populate the settings based on command line arguments.
  context->PopulateSettings(&settings);

  settings.multi_threaded_message_loop=1; 

  // Initialize CEF.
  // Initialize CEF.
  // Initialize CEF.
  context->Initialize(main_args, settings, app, sandbox_info);
  // Initialize CEF.
  // Initialize CEF.
  // Initialize CEF.

  auto looper = new MainMessageLoopMultithreadedWin();

  RootWindowConfig window_config;
  window_config.always_on_top = 0;
  window_config.with_controls = 1;
  window_config.with_osr = /*windowless_rendering_enabled*/0 ? true : false;
  
  // Create the first window.
  //context->GetRootWindowManager()->CreateRootWindow(window_config);

  // Run the message loop. This will block until Quit() is called by the
  // RootWindowManager after all windows have been destroyed.

  HWND hwnd;
  {
	  regWndClass(L"ASDASD", CS_HREDRAW | CS_VREDRAW);
	  hwnd = ::CreateWindowEx(WS_EX_APPWINDOW , L"ASDASD" , NULL
		  , WS_OVERLAPPEDWINDOW | WS_VISIBLE , 0 , 0 , 840 , 680 , NULL , NULL , g_hInstance, NULL);

	  ShowWindow(hwnd, true);
  }

	CefBrowserSettings browser_settings;
	CefWindowInfo window_info;
	RECT rc;
	GetWindowRect(hwnd, &rc);
	//rc.bottom -= 160;
	window_info.SetAsChild(hwnd, rc);

	CefRefPtr<ClientHandler>  g_handler = new ClientHandlerStd(0, "www.baidu.com");
	CefRefPtr<CefDictionaryValue> extra_info;
	CefRefPtr<CefRequestContext> request_context;
	CefBrowserHost::CreateBrowser(window_info, g_handler, "www.baidu.com", browser_settings, extra_info, request_context);

  hAccelTable = LoadAccelerators(g_hInstance, MAKEINTRESOURCE(IDC_CEFCLIENT));

  looper->Run();

  MSG msg;

  {
	  // Run the application message loop.
	  while (GetMessage(&msg, NULL, 0, 0)) {
		  // Allow processing of dialog messages.
		  //if ((looper->dialog_hwnd_ && IsDialogMessage(looper->dialog_hwnd_ , &msg)))
			//  continue;

		  if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) {
			  TranslateMessage(&msg);
			  DispatchMessage(&msg);
		  }
	  }

  }

  //DestroyWindow(looper->message_hwnd_);
  //delete looper;

  int result = static_cast<int>(msg.wParam);

  // Shut down CEF.
  context->Shutdown();

  // Release objects in reverse order of creation.
  //message_loop.reset();
  context.reset();

  return result;
}




}  // namespace
}  // namespace client

#ifndef DLL
// Program entry point function.
int APIENTRY wWinMain(HINSTANCE hInstance,
                      HINSTANCE hPrevInstance,
                      LPTSTR lpCmdLine,
                      int nCmdShow) {
 // HANDLE mutex = ::CreateMutex(NULL, false, TEXT("HAPPY"));
  //if (::GetLastError() == ERROR_ALREADY_EXISTS)
//	  return 0;

  return client::RunMain(hInstance, nCmdShow);
}
#else
BOOL APIENTRY DllMain( HANDLE hModule, 
	DWORD  reasonForCall, 
	LPVOID lpReserved )
{
	//::MessageBox(NULL, TEXT("DllMain"), TEXT(""), MB_OK);
	switch (reasonForCall)
	{
	case DLL_PROCESS_ATTACH:
	{
		break;
	}

	case DLL_PROCESS_DETACH:
		break;
	case DLL_THREAD_ATTACH:
		break;

	case DLL_THREAD_DETACH:
		break;
	}

	return TRUE;
}
#endif

extern "C" __declspec(dllexport) void * RunMain(HINSTANCE hInstance, bool nCmdShow)
{
	//::MessageBox(NULL, TEXT("RunMain"), TEXT(""), MB_OK);
	client::RunMain(hInstance, nCmdShow);
	return 0;
}
