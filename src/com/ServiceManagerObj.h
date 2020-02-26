#pragma once

#include "generated/IServiceManager.h"

#include "../ServiceManagement/ServiceManager.h"

class ServiceManagerObj : public IServiceManager {
	public:
		//IUnknown interface 
		HRESULT __stdcall QueryInterface(REFIID riid, void **ppObj);
		ULONG   __stdcall AddRef();
		ULONG   __stdcall Release();
		
		//IServiceManager interface
		HRESULT __stdcall init(void);
		HRESULT __stdcall enumetateServiceNames(SAFEARRAY **pServices);
	private:
		long m_RefCnt;
		
		ServiceManagement::ServiceManager m_ServiceManager;
};