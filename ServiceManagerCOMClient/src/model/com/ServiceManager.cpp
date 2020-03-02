#include "ServiceManager.h"
#include <iostream>
namespace com {
  ServiceManager::~ServiceManager(void) {
    if (m_Manager != nullptr)
      m_Manager->Release();

    CoUninitialize();
  }

	HRESULT ServiceManager::init(void) {
    HRESULT hr;
    IUnknown* unknown;

    hr = CoInitialize(nullptr);
    if (FAILED(hr)) return hr;

    hr = CoCreateInstance(CLSID_ServiceManagerObj, nullptr, CLSCTX_INPROC_SERVER, IID_IUnknown, (void**) &unknown);
    if (FAILED(hr)) return hr;
    
    hr = unknown->QueryInterface(IID_IServiceManager, (void**) &m_Manager);
    if (FAILED(hr)) return hr;

    return m_Manager->init();
	}

  HRESULT ServiceManager::enumerateServiceNames(std::vector<std::wstring>& result) const {
    HRESULT hr;

    SAFEARRAY* buffer;
    hr = m_Manager->enumetateServicesInfo(&buffer);
    if (FAILED(hr)) return hr;

    CComSafeArray<VARIANT> serviceNames;
    serviceNames.Attach(buffer);
    
    std::cout << serviceNames.GetCount() << std::endl;
    
    for (LONG i = 0; i < serviceNames.GetCount(); ++i) {
      CComVariant variant(serviceNames[i]);
      
      TServiceInfo* pInfo = static_cast<TServiceInfo*>(variant.pvRecord);
      std::wcout << (variant.vt == VT_RECORD) << std::endl;
      result.push_back(pInfo->m_DisplayName);
    }
    
    return S_OK;
  }
} // namespace com