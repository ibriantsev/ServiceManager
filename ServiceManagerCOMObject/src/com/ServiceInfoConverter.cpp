#include "ServiceInfoConverter.h"

#include "Util.h"
#include "ServiceConstantConverter.h"
#include "IServiceManager.h"
#include "GUIDS.c"

#include <atlcomcli.h>

namespace com {
	HRESULT getRecordFromGUID(REFGUID typeUUID, IRecordInfo** pRecordInfo) {
		HRESULT hr;
		
		std::wstring moduleName;
		hr = util::getCurrentModuleName(moduleName);
		if (FAILED(hr)) return hr;
		
		ITypeLib* pTypeLib = nullptr;
		hr = LoadTypeLibEx(moduleName.c_str(), REGKIND_NONE, &pTypeLib);
		if (FAILED(hr)) return hr;
		
		ITypeInfo* pTypeInfo = nullptr;
		hr = pTypeLib->GetTypeInfoOfGuid(__uuidof(TServiceInfo), &pTypeInfo);
		if (FAILED(hr)) return hr;
		
		hr = GetRecordInfoFromTypeInfo(pTypeInfo, pRecordInfo);
		pTypeInfo->Release();
		pTypeLib->Release();
		
		return hr;
	}

	HRESULT ServiceInfoConverter::convertToVariant(const ServiceManagement::ServiceInfo& serviceInfo, VARIANT& variant) {
    HRESULT hr = E_UNEXPECTED;

		EServiceState serviceState;
		hr = ServiceConstantConverter::convertServiceState(serviceInfo.m_CurrentState, serviceState);
		if (FAILED(hr)) return hr;

		IRecordInfo* pRecordInfo = nullptr;
		getRecordFromGUID(__uuidof(TServiceInfo), &pRecordInfo);
		
		TServiceInfo* info  = static_cast<TServiceInfo *>(pRecordInfo->RecordCreate());
		if (!info)
			return STG_E_INSUFFICIENTMEMORY;

		info->m_ServiceName = CComBSTR(serviceInfo.m_ServiceName.data()).Detach();
		info->m_DisplayName = CComBSTR(serviceInfo.m_DisplayName.data()).Detach();
		info->m_Type = serviceInfo.m_Type;
		info->m_CurrentState = serviceState;
		info->m_ProcessId = serviceInfo.m_ProcessId;

		VariantInit(&variant);
		variant.vt = VT_RECORD;
		variant.pvRecord = info;
		variant.pRecInfo = pRecordInfo;

		return S_OK;
	}
} // namespace com