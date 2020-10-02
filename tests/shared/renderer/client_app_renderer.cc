// Copyright (c) 2013 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#include "tests/shared/renderer/client_app_renderer.h"
#include "tests/cefclient/browser/client_handler.h"

#include "include/base/cef_logging.h"

class ClientHandler;
extern std::map<int, client::ClientHandler*> tmp_bid_2_client_table;
namespace client {
	// 一个注入绑定一个V8Handler
	bool BWV8Handler::Execute(const CefString& name, CefRefPtr<CefV8Value> object, const CefV8ValueList& arguments
		, CefRefPtr<CefV8Value>& retval, CefString& exception) {
		//::MessageBox(NULL, TEXT("Execute V8Handler"), TEXT(""), MB_OK);
		if(bwJs2Native)
		{
			auto native_ret = bwJs2Native(&name, arguments.size(), &arguments, sizeof(BJSCV));
			if(native_ret)
			{
				switch(native_ret->value_type)
				{
					case typeInt:
						retval = CefV8Value::CreateInt(native_ret->intVal);
					break;
					case typeString:
						retval = CefV8Value::CreateString(native_ret->charVal);
					break;
					case typeBool:
						retval = CefV8Value::CreateBool(native_ret->boolVal);
					break;
					case typeDouble:
						retval = CefV8Value::CreateDouble(native_ret->doubleVal);
					break;
				}
				if(native_ret->delete_internal&&native_ret->charVal)
				{
					delete[] native_ret->charVal;
				}
				delete native_ret;
				return true;
			}
		}

		return false;
	}

	ClientAppRenderer::ClientAppRenderer() {
		CreateDelegates(delegates_);
	}

	void ClientAppRenderer::OnWebKitInitialized() {
		DelegateSet::iterator it = delegates_.begin();
		for (; it != delegates_.end(); ++it)
		(*it)->OnWebKitInitialized(this);
	}

	void ClientAppRenderer::OnBrowserCreated(
		CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefDictionaryValue> extra_info) {
		DelegateSet::iterator it = delegates_.begin();
		for (; it != delegates_.end(); ++it)
		(*it)->OnBrowserCreated(this, browser, extra_info);
	}

	void ClientAppRenderer::OnBrowserDestroyed(CefRefPtr<CefBrowser> browser) {
		DelegateSet::iterator it = delegates_.begin();
		for (; it != delegates_.end(); ++it)
		(*it)->OnBrowserDestroyed(this, browser);
	}

	CefRefPtr<CefLoadHandler> ClientAppRenderer::GetLoadHandler() {
		CefRefPtr<CefLoadHandler> load_handler;
		DelegateSet::iterator it = delegates_.begin();
		for (; it != delegates_.end() && !load_handler.get(); ++it)
		load_handler = (*it)->GetLoadHandler(this);

		return load_handler;
	}

	void OnContextCreatedPtr(int id, CefRefPtr<CefV8Value> window) {
		auto client_it = tmp_bid_2_client_table.find(id);

		if(client_it!=tmp_bid_2_client_table.end())
		{
			auto client = client_it->second;
			if(client)
			{
				auto pool =  client->_bwV8HandlerPool;
				if(pool)
				{
					for(auto bwh:*pool)
					{
						CefRefPtr<CefV8Value> func = CefV8Value::CreateFunction(bwh->name, bwh);
						window->SetValue(bwh->name, func, V8_PROPERTY_ATTRIBUTE_NONE);
					}
				}
			}
		}
	}
	
	void ClientAppRenderer::OnContextCreated(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefRefPtr<CefV8Context> context) {
		// Retrieve the context's window object.
		//if (!CefCurrentlyOn(TID_UI)) {
		//	// Execute on the browser IO thread.
		//	CefPostTask(TID_UI, base::Bind(OnContextCreatedPtr, browser->GetIdentifier(), context->GetGlobal()));
		//	return;
		//}
		OnContextCreatedPtr(browser->GetIdentifier(), context->GetGlobal()); // 多进程模式过于复杂，不予考虑。
		DelegateSet::iterator it = delegates_.begin();
		for (; it != delegates_.end(); ++it)
			(*it)->OnContextCreated(this, browser, frame, context);
	}

	void ClientAppRenderer::OnContextReleased(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefRefPtr<CefV8Context> context) {
		DelegateSet::iterator it = delegates_.begin();
		for (; it != delegates_.end(); ++it)
		(*it)->OnContextReleased(this, browser, frame, context);
	}

	void ClientAppRenderer::OnUncaughtException(
		CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		CefRefPtr<CefV8Context> context,
		CefRefPtr<CefV8Exception> exception,
		CefRefPtr<CefV8StackTrace> stackTrace) {
		DelegateSet::iterator it = delegates_.begin();
		for (; it != delegates_.end(); ++it) {
			(*it)->OnUncaughtException(this, browser, frame, context, exception,
			stackTrace);
		}
	}

	void ClientAppRenderer::OnFocusedNodeChanged(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		CefRefPtr<CefDOMNode> node) {
		DelegateSet::iterator it = delegates_.begin();
		for (; it != delegates_.end(); ++it)
		(*it)->OnFocusedNodeChanged(this, browser, frame, node);
	}

	bool ClientAppRenderer::OnProcessMessageReceived(
		CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		CefProcessId source_process,
		CefRefPtr<CefProcessMessage> message) {
		DCHECK_EQ(source_process, PID_BROWSER);

		bool handled = false;

		DelegateSet::iterator it = delegates_.begin();
		for (; it != delegates_.end() && !handled; ++it) {
			handled = (*it)->OnProcessMessageReceived(this, browser, frame,
			source_process, message);
		}

		return handled;
	}

}  // namespace client
