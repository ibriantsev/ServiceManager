#include "ServiceInfoConverter.h"

#include "IServiceManager.h"
#include "GUIDS.c"

namespace com {
	HRESULT ServiceInfoConverter::convertToVariant(const ServiceManagement::ServiceInfo& serviceInfo, VARIANT& variant) {
    HRESULT hr;

    IRecordInfo* pRecordInfo = nullptr;
    hr = GetRecordInfoFromGuids(LIBID_ServiceManagement, 1, 0, LOCALE_USER_DEFAULT, __uuidof(TServiceInfo), &pRecordInfo);
		if (FAILED(hr)) return hr;

		TServiceInfo* info  = static_cast<TServiceInfo *>(pRecordInfo->RecordCreate());
		if (!info)
			return STG_E_INSUFFICIENTMEMORY;

		info->m_ServiceName = CComBSTR(serviceInfo.m_ServiceName.data());
		info->m_DisplayName = CComBSTR(serviceInfo.m_DisplayName.data());
		info->m_Type = serviceInfo.m_Type;
		info->m_CurrentState = serviceInfo.m_CurrentState;
		info->m_ProcessId = serviceInfo.m_ProcessId;

		VariantInit(&variant);
		variant.vt = VT_RECORD;
		variant.pvRecord = info;
		variant.pRecInfo = pRecordInfo;

		return S_OK;
	}
} // namespace com