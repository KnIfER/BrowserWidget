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
#include "tests\cefclient\browser\bw.h"

#include "tests/cefclient/browser/resource.h"

// When generating projects with CMake the CEF_USE_SANDBOX value will be defined
// automatically if using the required compiler version. Pass -DUSE_SANDBOX=OFF
// to the CMake command-line to disable use of the sandbox.
// Uncomment this line to manually enable sandbox support.
// #define CEF_USE_SANDBOX 1

//extern  HINSTANCE g_hInstance;

//#undef CEF_USE_SANDBOX 

#if defined(CEF_USE_SANDBOX)
// The cef_sandbox.lib static library may not link successfully with all VS
// versions.
#pragma comment(lib, "cef_sandbox.lib")
#endif

HINSTANCE g_hInstance;

HWND hwnd;

client::MainContextImpl * pMainContextImpl;

client::MainMessageLoopMultithreadedWin* looper;

//internal
LRESULT WINAPI wWindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return ::DefWindowProc(hWnd, msg, wParam, lParam);
}

void decorateCommandLine(TCHAR** backUp)
{
	auto cmd = GetCommandLine();
	{
		//if(false)
		if(backUp)
		{
			if (!*backUp)
			{
				*backUp = new TCHAR[lstrlen(cmd)+8];
			}
			lstrcpy(*backUp, cmd);
		}
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
		{//
			lstrcpy(idx, TEXT(" -single-process -no-proxy-server -disable-logging --default-encoding=UTF8 "));
		}
	}
}

// test exposed
LRESULT WINAPI testWindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;
	//mbWebView view = (mbWebView)::GetProp(hWnd, L"mb");
	//if (!view)
	//	return ::DefWindowProc(hWnd, msg, wParam, lParam);

	switch (msg) { 

	case WM_ERASEBKGND:
		return TRUE;

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

			//::MessageBox(NULL, TEXT("WM_CONTEXTMENU"), TEXT(""), MB_OK);
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
	case WM_CLOSE: {
			break;
		}
	case WM_DESTROY:
		if(hWnd==hwnd)
		{
			PostQuitMessage( 0 );
		}
		break;
	}
	return wWindowProc(hWnd, msg, wParam, lParam);
}

extern "C" __declspec(dllexport) HWND bwGetHWNDForBrowser(CefRefPtr<CefBrowser>* pBrowser)
{
	CefRefPtr<CefBrowser> & browser = *pBrowser;
	return browser?browser->GetHost()->GetWindowHandle():0;
}

extern "C" __declspec(dllexport) void bwLoadStrData(CefRefPtr<CefBrowser>* pBrowser, const CHAR* virturl, const CHAR* data, size_t len)
{
	if(pBrowser)
	{
		if(!len)
		{
			len = strlen(data);
		}
		client::test_runner::LoadStrResourcePage(*pBrowser, virturl, data, len);
	}
}

extern "C" __declspec(dllexport) int bwLoadUrl(CefRefPtr<CefBrowser>* pBrowser, CHAR* URL)
{
	if(pBrowser)
	{
		(*pBrowser)->GetMainFrame()->LoadURL(URL);
		return 1;
	}
	return 0;
}

class BJSC_EXECUTION;

extern "C" __declspec(dllexport) void bwInstallJsNativeToWidget(CefRefPtr<CefBrowser>* pBrowser, const char* name, client::BJSC_EXECUTION native_callback)
{
	if(pBrowser)
	{
		auto *pool =  &((client::ClientHandler*)(*pBrowser)->GetHost()->GetClient().get())->_bwV8HandlerPool;
		if(!*pool)
		{
			*pool = new std::vector<CefRefPtr<client::BWV8Handler>>();
		}
		(*pool)->push_back(new client::BWV8Handler(name, native_callback));
	}
}

extern "C" __declspec(dllexport) client::BJSCV* bwParseCefV8Args(std::vector<CefRefPtr<CefV8Value>>* args, int & sizeofBJSCV, bool strToChar)
{
	int i=0,len=args->size();
	sizeofBJSCV=sizeof(client::BJSCV);
	client::BJSCV* ret = (client::BJSCV*)malloc(sizeofBJSCV*len);
	for(;i<len;i++)
	{
		CefRefPtr<CefV8Value> & argI = args->at(i);
		ret[i].value_type=client::ValueType::typeNull;
		if(argI->IsInt())
		{
			ret[i].intVal=argI->GetIntValue();
			ret[i].value_type=client::ValueType::typeInt;
		}
		else if(argI->IsString())
		{
			//ret[i].charValPtr=(LONG_PTR)new CefRefPtr<CefV8Value>(argI);
			//::MessageBox(0, argI->GetStringValue().c_str(), TEXT(""), MB_OK);
			CefString & sv = argI->GetStringValue();
			TCHAR* str=(TCHAR*)sv.c_str();
			if (strToChar)
			{
				int len = WideCharToMultiByte(CP_ACP, 0, str, sv.length(), 0, 0, 0, 0);
				if (len>=0)
				{
					char* data = new char[len+1]{0};
					WideCharToMultiByte(CP_ACP, 0, str, sv.length(), data, len, 0, 0);
					data[len]='\0';
					ret[i].charVal = data;
					//::MessageBoxA(0, ret[i].charVal, (""), MB_OK);
				}
			}
			else
			{
				ret[i].charVal = (CHAR*)str;
			}
			ret[i].value_type=client::ValueType::typeString;
		}
		else if(argI->IsBool())
		{
			ret[i].boolVal=argI->GetBoolValue();
			ret[i].value_type=client::ValueType::typeBool;
		}
		else if(argI->IsDouble())
		{
			ret[i].doubleVal=argI->GetDoubleValue();
			ret[i].value_type=client::ValueType::typeDouble;
		}
	}
	return ret;
}

extern "C" __declspec(dllexport) char* bwGetString(CefRefPtr<CefString>* string)
{
	return (char*)string->get()->c_str();
}

extern "C" __declspec(dllexport) void bwReleaseString(CHAR* data)
{
	delete[] data;
}

extern "C" __declspec(dllexport) int bwLoadString(CefRefPtr<CefBrowser>* pBrowser, CHAR* URL, const CHAR* Data, size_t length)
{
	if(pBrowser)
	{
		client::test_runner::LoadStrResourcePage(*pBrowser, URL, Data, length);
	}
	return 0;
}

extern "C" __declspec(dllexport) TCHAR* bwGetUrl(CefRefPtr<CefBrowser>* pBrowser)
{
	if(pBrowser)
	{
		return (TCHAR*)(*pBrowser)->GetMainFrame()->GetURL().c_str();
	}
	return 0;
}

extern "C" __declspec(dllexport) void bwExecuteJavaScript(CefRefPtr<CefBrowser>* pBrowser, CHAR* JS)
{
	if(pBrowser)
	{
		(*pBrowser)->GetMainFrame()->ExecuteJavaScript(JS, "", 0);
	}
}

extern "C" __declspec(dllexport) bool bwCanGoBack(CefRefPtr<CefBrowser>* pBrowser)
{
	if(pBrowser)
	{
		return (*pBrowser)->CanGoBack();
	}
	return false;
}

extern "C" __declspec(dllexport) void bwRefresh(CefRefPtr<CefBrowser>* pBrowser)
{
	if(pBrowser)
	{
		(*pBrowser)->Reload();
	}
}

extern "C" __declspec(dllexport) void bwGoBack(CefRefPtr<CefBrowser>* pBrowser)
{
	if(pBrowser)
	{
		(*pBrowser)->GoBack();
	}
}

extern "C" __declspec(dllexport) bool bwCanGoForward(CefRefPtr<CefBrowser>* pBrowser)
{
	if(pBrowser)
	{
		return (*pBrowser)->CanGoForward();
	}
	return false;
}

extern "C" __declspec(dllexport) void bwGoForward(CefRefPtr<CefBrowser>* pBrowser)
{
	if(pBrowser)
	{
		(*pBrowser)->GoForward();
	}
}

extern "C" __declspec(dllexport) void bwDestroyWebview(CefRefPtr<CefBrowser>* pBrowser, bool exit)
{
	// what a mess ……
	if(exit&&1) 
	{
		(*pBrowser)->GetHost()->CloseBrowser(true);
		(*pBrowser)->Release();
		return;
	}

	if(exit&&0) 
	{
		(*pBrowser)->Release();
		return;
	}

	if (!CefCurrentlyOn(TID_UI)) {
		CefPostTask(TID_UI, base::Bind(bwDestroyWebview, pBrowser, exit));
		return;
	}

	if(pBrowser)
	{
		CefRefPtr<CefBrowser> ptr(*pBrowser);
		if(ptr->HasAtLeastOneRef()) 
		{
			(*pBrowser)->Release();
			((client::ClientHandler*)ptr->GetHost()->GetClient().get())->DoClose(ptr);
			DestroyWindow(ptr->GetHost()->GetWindowHandle());

			ptr->GetHost()->CloseBrowser(true);
			//ptr->Release(); // don't do it
		}
	}

	if(exit && looper) 
	{
		looper->Quit();
		pMainContextImpl->Shutdown();
		delete looper;
		looper = 0;
	}
	//CefShutdown();
}

extern "C" __declspec(dllexport) double bwGetZoomLevel(CefRefPtr<CefBrowser>* pBrowser)
{
	if(pBrowser)
	{
		return (*pBrowser)->GetHost()->GetZoomLevel();
	}
}

extern "C" __declspec(dllexport) void bwSetZoomLevel(CefRefPtr<CefBrowser>* pBrowser, double val)
{
	if (!CefCurrentlyOn(TID_UI)) {
		CefPostTask(TID_UI, base::Bind(bwSetZoomLevel, pBrowser, val));
		return;
	}
	if(pBrowser)
	{
		return (*pBrowser)->GetHost()->SetZoomLevel(val);
	}
}

extern "C" __declspec(dllexport) void bwZoomLevelDelta(CefRefPtr<CefBrowser>* pBrowser, double delta)
{
	if (!CefCurrentlyOn(TID_UI)) {
		CefPostTask(TID_UI, base::Bind(bwZoomLevelDelta, pBrowser, delta));
		return;
	}
	if(pBrowser)
	{
		auto val=(*pBrowser)->GetHost()->GetZoomLevel()+delta;
		if(val>8)val=8;
		if(val<-8)val=-8;
		return (*pBrowser)->GetHost()->SetZoomLevel(val);
	}
}

extern "C" __declspec(dllexport) void bwShowDevTools(CefRefPtr<CefBrowser>* pBrowser)
{
	if(pBrowser)
	{
		((client::ClientHandler*)(*pBrowser)->GetHost()->GetClient().get())->ShowDevTools((*pBrowser), 0);
	}
}

namespace client {
	namespace {
		int RunMain(HINSTANCE hInstance, int nCmdShow) {
			// Enable High-DPI support on Windows 7 or newer.
			CefEnableHighDPISupport();

			CefMainArgs main_args(g_hInstance);

			void* sandbox_info = nullptr;
			// Parse command-line arguments.
			CefRefPtr<CefCommandLine> command_line = CefCommandLine::CreateCommandLine();
			command_line->AppendSwitch("no-proxy-server");

			// Create a ClientApp of the correct type.
			CefRefPtr<ClientApp> app = new ClientAppBrowser();

			// Execute the secondary process, if any.
			int exit_code = CefExecuteProcess(main_args, app, sandbox_info);
			if (exit_code >= 0)
			return exit_code;


			decorateCommandLine(nullptr);


			// Create the main context object.
			scoped_ptr<MainContextImpl> context(new MainContextImpl(command_line, true));

			CefSettings settings;
			settings.Set({}, 0);
			CefString(&settings.application_client_id_for_file_scanning).FromString("9A8DE24D-B822-4C6C-8259-5A848FEA1E68");
			context->PopulateSettings(&settings);
			settings.command_line_args_disabled=0;
			//settings.no_sandbox = true;
			//settings.log_severity=LOGSEVERITY_DISABLE;

			settings.multi_threaded_message_loop=1;
			looper = new MainMessageLoopMultithreadedWin();

			// Initialize CEF.
			context->Initialize(main_args, settings, app, sandbox_info);

			RootWindowConfig window_config;
			window_config.always_on_top = false;
			window_config.with_controls = true;
			window_config.with_osr = false; 

			// Create the first window.
			auto Browser = context->GetRootWindowManager()->CreateRootWindow(window_config);

			looper->agent=true;
			looper->Run();

			//::MessageBoxA(NULL, ("111"), (""), MB_OK);
			Browser->Close(true);
			//context->Shutdown();
			context.reset();
			delete looper;
			//exit(0);
			return 0;
		}


		BOOL regWndClass(LPCTSTR lpcsClassName, DWORD dwStyle)
		{
			WNDCLASS wndclass = { 0 };

			wndclass.style = dwStyle;
			wndclass.lpfnWndProc = testWindowProc;
			wndclass.cbClsExtra = 0;
			wndclass.cbWndExtra = 0;
			wndclass.hInstance = g_hInstance;
			wndclass.hIcon = NULL;
			//wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
			wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
			wndclass.lpszMenuName = NULL;
			wndclass.lpszClassName = lpcsClassName;

			::RegisterClass(&wndclass);
			return TRUE;
		}

		void Test_browser_prepared(CefRefPtr<CefBrowser>* browser)
		{
			HWND hwnd = bwGetHWNDForBrowser(browser);
			if(hwnd)
			{
				MoveWindow(hwnd, 0, 0, 500, 500, 1);
			}
		}

		void Test_browsercallback1(CefRefPtr<CefBrowser>* browser)
		{
			HWND hwnd = bwGetHWNDForBrowser(browser);
			if(hwnd)
			{
				MoveWindow(hwnd, 0, 500, 500, 500, 1);
			}
		}

		BJSCV* Test_JSCallback(const CefString* funcName, int argc, const CefV8ValueList* argv, int sizeofBJSCV)
		{
			return new BJSCV{typeString, 0, "HAPPY"};
		}

		struct BWCreateOptions{
			HWND hParent=0;
			const CHAR* URL=nullptr;
			BC_BrowserCallback bcCallback=0;
			BC_URLInterceptor bcInterceptor=0;
			BC_SETFOCUS bcSetFocus=nullptr;
			BC_SHOULDCLOSE bcShouldClose=nullptr;
			const CHAR* content=nullptr;
			//std::vector<CefRefPtr<BWV8Handler>>* bcRenderHandlers=0;
		};

		extern "C" __declspec(dllexport) int bwCreateBrowser(BWCreateOptions BWOpt) {
			if(!looper)
			{
				// Enable High-DPI support on Windows 7 or newer.
				//CefEnableHighDPISupport();
				CefMainArgs main_args(g_hInstance);

				void* sandbox_info = nullptr;

#if defined(CEF_USE_SANDBOX)
				// Manage the life span of the sandbox information object. This is necessary
				// for sandbox support on Windows. See cef_sandbox_win.h for complete details.
				CefScopedSandboxInfo scoped_sandbox;
				sandbox_info = scoped_sandbox.sandbox_info();
#endif

				// Parse command-line arguments.
				CefRefPtr<CefCommandLine> command_line = CefCommandLine::CreateCommandLine();

				CefRefPtr<CefApp> app = new ClientAppBrowser();

				//int cmd_len = lstrlen(::GetCommandLine());
				TCHAR* cmd_extra = NULL;
				decorateCommandLine(&cmd_extra);

				// Execute the secondary process, if any.
				int exit_code = CefExecuteProcess(main_args, app, sandbox_info);

				if (exit_code >= 0)
				return 0;

				pMainContextImpl = new MainContextImpl(command_line, true); // Create the main context object.

				CefSettings settings;
				settings.Set({}, 0);
				CefString(&settings.application_client_id_for_file_scanning).FromString("9A8DE24D-B822-4C6C-8259-5A848FEA1E68");
				//context->PopulateSettings(&settings);
				settings.command_line_args_disabled=0;
				settings.no_sandbox = false;
				settings.log_severity=LOGSEVERITY_DISABLE;
				settings.multi_threaded_message_loop=1;
				//settings.background_color = 0xff000000;

				//const char* loc = "zh-CN";
				//CefString(&settings.locale).FromASCII(loc);


				// Initialize CEF.
				bool succ = pMainContextImpl->Initialize(main_args, settings, app, sandbox_info);
				// Initialize CEF.

				if(succ)
				{
					looper = new MainMessageLoopMultithreadedWin();
					looper->agent=false;
					looper->Run();
				}

				if (cmd_extra)
				{
					lstrcpy(::GetCommandLine(), cmd_extra);
					//::GetCommandLine()[cmd_len]='\0';
					//delete[] cmd_extra;
				}
			}

			if(looper)
			{
				CefRefPtr<ClientHandler>  g_handler = new ClientHandlerStd(0, BWOpt.URL, BWOpt.bcInterceptor, 0);
				CefBrowserSettings browser_settings;
				CefWindowInfo window_info;
				RECT rc;
				if(IsWindow(BWOpt.hParent))
				{
					GetWindowRect(BWOpt.hParent, &rc);
					window_info.SetAsChild(BWOpt.hParent, rc);

				CefRefPtr<CefDictionaryValue> extra_info;
				CefRefPtr<CefRequestContext> request_context;

					g_handler->IsEmbeded = true;
					g_handler->_bw_callback = BWOpt.bcCallback;
					g_handler->_bw_setfocus = BWOpt.bcSetFocus;
					g_handler->_bw_shouldclose = BWOpt.bcShouldClose;
					g_handler->_bwV8HandlerPool = new std::vector<CefRefPtr<BWV8Handler>>();
					g_handler->_bwV8HandlerPool->push_back(new BWV8Handler("testJs", Test_JSCallback));
					if(BWOpt.content) {
						g_handler->SetStrResource(BWOpt.URL, BWOpt.content, strlen(BWOpt.content));
					}
					return CefBrowserHost::CreateBrowser(window_info, g_handler, BWOpt.URL, browser_settings, extra_info, request_context);
				}
				else
				{ // window mode.
					RootWindowConfig window_config;
					window_config.always_on_top = 0;
					window_config.with_controls = 1;
					window_config.with_osr = /*windowless_rendering_enabled*/0 ? true : false;
					window_config.url = BWOpt.URL;
					window_config.bcInterceptor = BWOpt.bcInterceptor;
					// todo wrap in bcCallback;
					// todo wrap in RenderV8Handler;
					// todo wrap in bcSetFocus;
					// todo wrap in bcShouldClose;

					auto Browser = pMainContextImpl->GetRootWindowManager()->CreateRootWindow(window_config);
					return 1;
				}
			}
			return 0;
		}

		url_intercept_result* Test_InterceptBaidu(const char* url, const url_intercept_result*){
			if(url==std::string("https://www.baidu.com/")) {
				//return new url_intercept_result{"HAPPY<script>console.log(window.testJs())</script>", 51, 200, "OK"};
			}
			return nullptr;
		}


		CefRefPtr<CefApp> app = new ClientAppBrowser();


		int MainRun1(HINSTANCE hInstance, int nCmdShow) 
		{
			//{
			//	regWndClass(L"ASDASD", CS_HREDRAW | CS_VREDRAW);
			//	hwnd = ::CreateWindowEx(0 , L"ASDASD" , NULL
			//	, WS_OVERLAPPEDWINDOW , 0 , 0 , 840 , 680 , NULL , NULL , g_hInstance, NULL);
			//	ShowWindow(hwnd, true);
			//}
			//
			//BWCreateOptions args = {hwnd, "www.baidu.com", Test_browser_prepared, Test_InterceptBaidu};
			//bwCreateBrowser(args);
			////args = {hwnd, "www.bing.com", (BrowserCallback)Test_browsercallback1, (URLInterceptor)Test_InterceptBaidu};
			////bwCreateBrowser(args);
			//
			//HACCEL hAccelTable = LoadAccelerators(g_hInstance, MAKEINTRESOURCE(IDC_CEFCLIENT));
			//
			//MSG msg;
			//{
			//	while (GetMessage(&msg, NULL, 0, 0)) {
			//		if ((looper && looper->dialog_hwnd_ && IsDialogMessage(looper->dialog_hwnd_ , &msg)))
			//		continue;
			//		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
			//		{
			//			TranslateMessage(&msg);
			//			DispatchMessage(&msg);
			//		}
			//	}
			//}
			//
			//return 1;

			// Enable High-DPI support on Windows 7 or newer.
			//CefEnableHighDPISupport();


			CefMainArgs main_args(hInstance);

			void* sandbox_info = nullptr;

			CefScopedSandboxInfo scoped_sandbox;
			sandbox_info = scoped_sandbox.sandbox_info();
			// Parse command-line arguments.
			CefRefPtr<CefCommandLine> command_line = CefCommandLine::CreateCommandLine();

			// Execute the secondary process, if any.
			int exit_code = CefExecuteProcess(main_args, app, sandbox_info);
			if (exit_code >= 0)
				return exit_code;

			TCHAR* cmd_extra = NULL;
			decorateCommandLine(&cmd_extra);

			if (cmd_extra)
			{
				delete[] cmd_extra;
			}

			// Create the main context object.
			pMainContextImpl = new MainContextImpl(command_line, true);

			CefSettings settings;

			settings.no_sandbox = true;
			// Applications should specify a unique GUID here to enable trusted downloads.
			CefString(&settings.application_client_id_for_file_scanning).FromString("9A8DE24D-B822-4C6C-8259-5A848FEA1E68");

			// Populate the settings based on command line arguments.
			pMainContextImpl->PopulateSettings(&settings);

			settings.multi_threaded_message_loop=1; 

			looper = new MainMessageLoopMultithreadedWin();
			looper->agent = true;

			// Initialize CEF.
			// Initialize CEF.
			// Initialize CEF.
			pMainContextImpl->Initialize(main_args, settings, app, sandbox_info);
			// Initialize CEF.
			// Initialize CEF.
			// Initialize CEF.


			RootWindowConfig window_config;
			window_config.always_on_top = 0;
			window_config.with_controls = 1;
			window_config.url = "https://www.baidu.com";
			window_config.with_osr = /*windowless_rendering_enabled*/0 ? true : false;

			// Create the first window.
			pMainContextImpl->GetRootWindowManager()->CreateRootWindow(window_config);

			// Run the message loop. This will block until Quit() is called by the
			// RootWindowManager after all windows have been destroyed.

			if(1) {
				regWndClass(L"ASDASD", CS_BYTEALIGNWINDOW | CS_DBLCLKS);
				hwnd = ::CreateWindowEx(0 , L"ASDASD" , TEXT("TEST")
					, (WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN) , 0 , 0 , 840 , 680 , NULL , NULL , g_hInstance, NULL);
				ShowWindow(hwnd, true);

				CefBrowserSettings browser_settings;
				CefWindowInfo window_info;
				RECT rc;
				GetWindowRect(hwnd, &rc);
				//rc.bottom -= 160;
				window_info.SetAsChild(hwnd, rc);

				CefRefPtr<ClientHandlerStd>  g_handler = new ClientHandlerStd(0, "www.baidu.com", 0, 0);
				CefRefPtr<CefDictionaryValue> extra_info;
				CefRefPtr<CefRequestContext> request_context;
				CefBrowserHost::CreateBrowser(window_info, g_handler, "www.baidu.com", browser_settings, extra_info, request_context);
			}

			//g_handler->_browser->GetMainFrame()->LoadURL("www.bing.com");

			looper->Run();

			return 0;

		}


		int MainRun(HINSTANCE hInstance, int nCmdShow) {
			{
				regWndClass(L"ASDASD", CS_BYTEALIGNWINDOW | CS_DBLCLKS);
				hwnd = ::CreateWindowEx(0 , L"ASDASD" , TEXT("TEST")
				, (WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN) , 0 , 0 , 840 , 680 , NULL , NULL , g_hInstance, NULL);
				ShowWindow(hwnd, true);
			}

			if(1)
			{
				// Enable High-DPI support on Windows 7 or newer.
				//CefEnableHighDPISupport();

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
				
				TCHAR* cmd_extra = NULL;
				decorateCommandLine(&cmd_extra);

				if (cmd_extra)
				{
					delete[] cmd_extra;
				}

				// Execute the secondary process, if any.
				int exit_code = CefExecuteProcess(main_args, app, sandbox_info);
				if (exit_code >= 0)
				return exit_code;

				// Create the main context object.
				pMainContextImpl = new MainContextImpl(command_line, true);

				CefSettings settings;

				settings.no_sandbox = true;
				// Applications should specify a unique GUID here to enable trusted downloads.
				CefString(&settings.application_client_id_for_file_scanning).FromString("9A8DE24D-B822-4C6C-8259-5A848FEA1E68");

				// Populate the settings based on command line arguments.
				pMainContextImpl->PopulateSettings(&settings);

				settings.multi_threaded_message_loop=1; 

				// Initialize CEF.
				// Initialize CEF.
				// Initialize CEF.
				pMainContextImpl->Initialize(main_args, settings, app, sandbox_info);
				// Initialize CEF.
				// Initialize CEF.
				// Initialize CEF.


				RootWindowConfig window_config;
				window_config.always_on_top = 0;
				window_config.with_controls = 1;
				window_config.with_osr = /*windowless_rendering_enabled*/0 ? true : false;

				// Create the first window.
				pMainContextImpl->GetRootWindowManager()->CreateRootWindow(window_config);

				// Run the message loop. This will block until Quit() is called by the
				// RootWindowManager after all windows have been destroyed.


				CefBrowserSettings browser_settings;
				CefWindowInfo window_info;
				RECT rc;
				GetWindowRect(hwnd, &rc);
				//rc.bottom -= 160;
				window_info.SetAsChild(hwnd, rc);

				CefRefPtr<ClientHandlerStd>  g_handler = new ClientHandlerStd(0, "www.baidu.com", 0, 0);
				CefRefPtr<CefDictionaryValue> extra_info;
				CefRefPtr<CefRequestContext> request_context;
				CefBrowserHost::CreateBrowser(window_info, g_handler, "www.baidu.com", browser_settings, extra_info, request_context);

				//g_handler->_browser->GetMainFrame()->LoadURL("www.bing.com");

				looper = new MainMessageLoopMultithreadedWin();
				looper->Run();
			}

			

			HACCEL hAccelTable = LoadAccelerators(g_hInstance, MAKEINTRESOURCE(IDC_CEFCLIENT));

			MSG msg;

			{
				// Run the application message loop.
				while (GetMessage(&msg, NULL, 0, 0)) {
					// Allow processing of dialog messages.
					//if ((looper && looper->dialog_hwnd_ && IsDialogMessage(looper->dialog_hwnd_ , &msg)))
					//  continue;
					if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
					{
						TranslateMessage(&msg);
						DispatchMessage(&msg);
					}
				}

			}

			//DestroyWindow(looper->message_hwnd_);
			//delete looper;

			int result = static_cast<int>(msg.wParam);

			// Shut down CEF.
			//context->Shutdown();

			// Release objects in reverse order of creation.
			//message_loop.reset();
			//context.reset();

			return result;
		}




	}  // namespace
}  // namespace client

#ifndef DLL
// Program entry point function.
int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine,
int nCmdShow) {
	// HANDLE mutex = ::CreateMutex(NULL, false, TEXT("HAPPY"));
	//if (::GetLastError() == ERROR_ALREADY_EXISTS)
	//	  return 0;

	return client::MainRun1(hInstance, nCmdShow);
	//return client::RunMain(hInstance, nCmdShow);
}
#else
BOOL APIENTRY DllMain(HANDLE hModule, DWORD  reasonForCall, LPVOID lpReserved )
{
	switch (reasonForCall)
	{
	case DLL_THREAD_ATTACH:
	case DLL_PROCESS_ATTACH:
		{
			g_hInstance=(HINSTANCE)hModule;
			break;
		}

	case DLL_PROCESS_DETACH:
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
