#pragma once

#include "IServiceManager.h"
#include "GUIDS.c"

#include "ServiceManager.h"

// {4fa8f5b0-f690-4152-90c4-32d67c26e4a8}
const CLSID CLSID_ServiceManagerObj = { 0x4fa8f5b0, 0xf690, 0x4152, { 0x90, 0xc4, 0x32, 0xd6, 0x7c, 0x26, 0xe4, 0xa8 } };

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
		HRESULT __stdcall enumetateServiceNames(SAFEARRAY **pServices);
	private:
		long m_RefCnt;
		ServiceManagement::ServiceManager m_ServiceManager;
};