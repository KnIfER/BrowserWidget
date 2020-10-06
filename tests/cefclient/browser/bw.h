#include "include/cef_base.h"
#include "include/cef_dom.h"
#include "include/cef_process_message.h"
#include "include/cef_request.h"
#include "include/cef_stream.h"
#include "include/cef_string_visitor.h"

#ifndef CEF_INCLUDE_BW_H_
#define CEF_INCLUDE_BW_H_
#pragma once

class CefBrowser;

struct url_intercept_result{
	CHAR* data;
	size_t length;
	int status_code;
	CHAR* status_text;
	CHAR mime[92]={0};
	bool delete_internal=false;
};


typedef void (__cdecl* BC_BrowserCallback)(CefRefPtr<CefBrowser>*);

typedef url_intercept_result* (__cdecl * BC_URLInterceptor)(std::string);

typedef bool (__cdecl * BC_SETFOCUS)(CefRefPtr<CefBrowser>*);

typedef bool (__cdecl * BC_SHOULDCLOSE)(CefRefPtr<CefBrowser>*);


#endif