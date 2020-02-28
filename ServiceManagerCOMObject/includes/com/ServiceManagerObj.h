#pragma once

#include "IServiceManager.h"
#include "GUIDS.c"

#include "ServiceManager.h"

extern long g_ObjCnt;

class __declspec(uuid("{4fa8f5b0-f690-4152-90c4-32d67c26e4a8}")) ServiceManagerObj : public IServiceManager {
	public:
		ServiceManagerObj(void) : m_RefCnt(0), m_ServiceManager() {
			++g_ObjCnt;
		}
		~ServiceManagerObj(void) {
			--g_ObjCnt;
		}
		//IUnknown interface 
		HRESULT __stdcall QueryInterface(REFIID riid, void **ppObj);
		ULONG   __stdcall AddRef();
		ULONG   __stdcall Release();
		
		//IServiceManager interface
		HRESULT __stdcall init(void);
		HRESULT __stdcall enumetateServiceNames(SAFEARRAY **ppServices);

		static constexpr CLSID CLSID = __uuidof(ServiceManagerObj);
		static constexpr auto ProgID = TEXT("COMServiceManagement.ServiceManagerObj");
	private:
		long m_RefCnt;
		ServiceManagement::ServiceManager m_ServiceManager;
};