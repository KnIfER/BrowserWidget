


#include <windows.h>
#include <shlwapi.h>
#include "BrowserUI.h"

HWND hBrowser;

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

	case WM_SIZE:
	{
		if(hBrowser)
		{
			RECT rc;
			GetClientRect(hWnd, &rc);
			::MoveWindow(hBrowser, rc.left, rc.top, rc.right, rc.bottom,1);
		}
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
	case WM_CLOSE: {
		break;
	}
	case WM_DESTROY: {
		PostQuitMessage( 0 );
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
	wndclass.hInstance = ::GetModuleHandle(NULL);
	wndclass.hIcon = NULL;
	//wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = lpcsClassName;

	::RegisterClass(&wndclass);
	return TRUE;
}

BJSCV* JSHAPPY(LONG_PTR funcName, int argc, LONG_PTR argv, int sizeofBJSCV)
{
	int structSize=0;
	char* args = bwParseCefV8Args(argv, structSize);
	if(structSize)
	{
		BJSCV* val = (BJSCV*)(args+0*structSize);
		if(val->value_type==typeString)
		{
			::MessageBox(NULL, (TCHAR*)val->charVal, TEXT(""), MB_OK);
		}
		// testJs('Hah')
	}
	return new BJSCV{typeString, 0, "HAPPY!"};
}

void onBrowserPrepared(bwWebView browserPtr)
{
	hBrowser = bwGetHWNDForBrowser(browserPtr);
	bwInstallJsNativeToWidget(browserPtr, "testJs", JSHAPPY);
}

url_intercept_result* InterceptBaidu(std::string url)
{
	if(url=="https://www.bing.com/") {
		return new url_intercept_result{(CHAR*)"HAPPY", 5, 200, (CHAR*)"OK"};
	}
	return nullptr;
}
int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow) {
	HWND hwnd=0;
	if(1)
	{
		regWndClass(L"ASDASD", CS_HREDRAW | CS_VREDRAW);
		hwnd = ::CreateWindowEx(WS_EX_APPWINDOW , L"ASDASD" , NULL
			, WS_OVERLAPPEDWINDOW | WS_VISIBLE , 0 , 0 , 840 , 680 , NULL , NULL , ::GetModuleHandle(NULL), NULL);

		ShowWindow(hwnd, true);
	}

	TCHAR buffer[MAX_PATH]; 
	GetModuleFileName(NULL, buffer, MAX_PATH);
	PathRemoveFileSpec(buffer);
	PathAppend(buffer, L"cefclient.dll");
	TCHAR LibBwgtPath[MAX_PATH]; 
	PathCanonicalize(LibBwgtPath, buffer);
	if(bwInit(LibBwgtPath))
	{
		bwCreateBrowser({hwnd, "www.bing.com", onBrowserPrepared, InterceptBaidu});
	}

	//if(pWIdGETINVOKER)
	//{
	//	pWIdGETINVOKER((HINSTANCE)hLibBwgt, nCmdShow);
	//}

	MSG msg;

	{
		while (GetMessage(&msg, NULL, 0, 0)) {
			//if ((looper->dialog_hwnd_ && IsDialogMessage(looper->dialog_hwnd_ , &msg)))
			//  continue;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return 0;
}
