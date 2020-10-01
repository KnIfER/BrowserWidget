#ifndef CEF_INCLUDE_BWUI_H_
#define CEF_INCLUDE_BWUI_H_
#pragma once

#include <windows.h>
#include <shlwapi.h>
#include <string>

// browser interface
namespace bw { class WebView; };
typedef bw::WebView* bwWebView;

struct url_intercept_result {
	CHAR* data;
	size_t length;
	int status_code;
	CHAR* status_text;
	CHAR mime[92]={0};
	bool delete_internal=false;
};

typedef void (__cdecl* BC_BrowserCallback)(bwWebView);

typedef url_intercept_result* (__cdecl * BC_URLInterceptor)(std::string);

struct BWCreateOptions{
	HWND hParent=0;
	const CHAR* URL=nullptr;
	BC_BrowserCallback bwCallback=0;
	BC_URLInterceptor bwInterceptor=0;
};

typedef void* (__cdecl* BW_WINDOWMODE)(HINSTANCE, bool);

typedef int (__cdecl* BW_CREATEBROWSER)(BWCreateOptions);

typedef HWND (__cdecl* BW_GETHWNDFORBROWSER)(bwWebView);

typedef void* (__cdecl* BW_LOADSTRDATA)(bwWebView, const CHAR*, const CHAR*, size_t);

/*__declspec(selectany)*/static BW_WINDOWMODE bwWindowMode = nullptr;

/*__declspec(selectany)*/static BW_CREATEBROWSER bwCreateBrowser = nullptr;

/*__declspec(selectany)*/static BW_GETHWNDFORBROWSER bwGetHWNDForBrowser = nullptr;

/*__declspec(selectany)*/static BW_LOADSTRDATA bwLoadStrData = nullptr;

// load module
static void PRINTMSG(TCHAR* buff, const CHAR* name, int & printed_len)
{
	int i=0, len=strlen(name);
	if(printed_len+len+6<74)
	{
		for(;i<len;i++) 
		{
			buff[printed_len+i]=name[i];
		}
		buff[printed_len+i]=' ';
		printed_len+=len+1;
	}
	else if(printed_len<74)
	{
		buff[++printed_len]='.';
	}
}

#define DEF_FUNC(hMod, func, type, name)\
	func = (type)GetProcAddress(hMod, name);\
	if(!func) PRINTMSG(PRINTBUFF, name, PRINTLEN);

static bool bwInit(TCHAR* LibBwgtPath)
{
	if(PathFileExists(LibBwgtPath))
	{
		const DWORD dwFlags = GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")), "AddDllDirectory") != NULL ? LOAD_LIBRARY_SEARCH_DLL_LOAD_DIR | LOAD_LIBRARY_SEARCH_DEFAULT_DIRS : 0;
		auto hLibBwgt = ::LoadLibraryEx(LibBwgtPath, NULL, dwFlags);
		if(hLibBwgt) 
		{
			TCHAR PRINTBUFF[75]=L"bw api not found : ";
			int PRINTLEN=lstrlen(PRINTBUFF);
			int PRINTLEN_0=PRINTLEN;
			DEF_FUNC(hLibBwgt, bwWindowMode, BW_WINDOWMODE, "RunMain");
			DEF_FUNC(hLibBwgt, bwCreateBrowser, BW_CREATEBROWSER, "bwCreateBrowser");
			DEF_FUNC(hLibBwgt, bwGetHWNDForBrowser, BW_GETHWNDFORBROWSER, "bwGetHWNDForBrowser");
			DEF_FUNC(hLibBwgt, bwLoadStrData, BW_LOADSTRDATA, "bwLoadStrData");
			if(PRINTLEN!=PRINTLEN_0)
			{
				PRINTBUFF[PRINTLEN]='\0';
				::MessageBox(NULL, PRINTBUFF, TEXT("BrowserWidget"), MB_OK);
			}
			return bwCreateBrowser!=0;
		}
	}
	return 0;
}

#endif