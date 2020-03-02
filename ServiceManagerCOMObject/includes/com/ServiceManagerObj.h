#pragma once

#include "IServiceManager.h"
#include "GUIDS.c"

#include "ServiceManager.h"

extern long g_ObjCnt;

class ServiceManagerObj : public IServiceManager {
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
		HRESULT __stdcall enumetateServicesInfo(SAFEARRAY **ppServices);

		static constexpr auto ProgID = TEXT("ComServiceManagement.ServiceManagerObj");
	private:
		long m_RefCnt;
		ServiceManagement::ServiceManager m_ServiceManager;
};