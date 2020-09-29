#include "include/cef_base.h"
#include "include/cef_dom.h"
#include "include/cef_process_message.h"
#include "include/cef_request.h"
#include "include/cef_stream.h"
#include "include/cef_string_visitor.h"

class CefBrowser;

typedef const void * (__cdecl * BrowserCallback)(CefBrowser*);