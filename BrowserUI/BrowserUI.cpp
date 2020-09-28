


#include <windows.h>
#include <shlwapi.h>

bool running=1;

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
	case WM_CLOSE: {
		running=0;
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


typedef const void * (__cdecl * WIdGETINVOKER)(HINSTANCE, bool);

WIdGETINVOKER pWIdGETINVOKER = nullptr;

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow) {
	TCHAR buffer[MAX_PATH]; 
	GetModuleFileName(NULL, buffer, MAX_PATH);
	PathRemoveFileSpec(buffer);
	PathAppend(buffer, L"cefclient.dll");
	TCHAR LibBwgtPath[MAX_PATH]; 
	PathCanonicalize(LibBwgtPath, buffer);
	if(PathFileExists(LibBwgtPath))
	{
		const DWORD dwFlags = GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")), "AddDllDirectory") != NULL ? LOAD_LIBRARY_SEARCH_DLL_LOAD_DIR | LOAD_LIBRARY_SEARCH_DEFAULT_DIRS : 0;
		auto hLibBwgt = ::LoadLibraryEx(LibBwgtPath, NULL, dwFlags);
		if(hLibBwgt)
		{
			pWIdGETINVOKER = (WIdGETINVOKER)GetProcAddress(hLibBwgt, "RunMain");
			if(pWIdGETINVOKER)
			{
				pWIdGETINVOKER((HINSTANCE)hLibBwgt, nCmdShow);
			}
		}
	}

	if(0)
	{
		HWND hwnd;
		{
			regWndClass(L"ASDASD", CS_HREDRAW | CS_VREDRAW);
			hwnd = ::CreateWindowEx(WS_EX_APPWINDOW , L"ASDASD" , NULL
				, WS_OVERLAPPEDWINDOW | WS_VISIBLE , 0 , 0 , 840 , 680 , NULL , NULL , ::GetModuleHandle(NULL), NULL);

			ShowWindow(hwnd, true);
		}

		MSG msg;

		{
			// Run the application message loop.
			while (running&&GetMessage(&msg, NULL, 0, 0)) {
				// Allow processing of dialog messages.
				//if ((looper->dialog_hwnd_ && IsDialogMessage(looper->dialog_hwnd_ , &msg)))
				//  continue;
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}

		}

	}

	return 0;
}
