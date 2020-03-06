#include "ServiceManager.h"

namespace model {
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

      hr = CoCreateInstance(CLSID_ServiceManagerObj, nullptr, CLSCTX_INPROC_SERVER, IID_IUnknown, (void**)&unknown);
      if (FAILED(hr)) return hr;

      hr = unknown->QueryInterface(IID_IServiceManager, (void**)&m_Manager);
      unknown->Release();
      if (FAILED(hr)) return hr;

      return m_Manager->init();
    }

    HRESULT ServiceManager::enumerateServicesInfo(std::vector<ServiceInfo>& result) const {
      HRESULT hr = E_UNEXPECTED;
      
      SAFEARRAY* buffer = nullptr;
      hr = m_Manager->enumetateServicesInfo(&buffer);
      if (FAILED(hr)) return hr;
      
      CComSafeArray<VARIANT> serviceNames(0UL);
      serviceNames.Attach(buffer);

      for (LONG i = 0; i < serviceNames.GetCount(); ++i) {
        TServiceInfo* pInfo = static_cast<TServiceInfo*>(serviceNames[i].pvRecord);
        result.push_back(ServiceInfo(pInfo->m_ServiceName, pInfo->m_DisplayName, pInfo->m_ProcessId));
      }
      return S_OK;
    }
  } // namespace com
} // namespace model