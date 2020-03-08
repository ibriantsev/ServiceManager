#pragma once 

#include "IServiceManager.h"

#include <string>

namespace model {
	struct ServiceInfo {
		ServiceInfo(const std::wstring& serviceName,
								const std::wstring& displayName,
								DWORD type,
								EServiceState state,
								DWORD processId)
		: m_ServiceName(serviceName), m_DisplayName(displayName), m_Type(type), m_CurrentState(state), m_ProcessId(processId) {
		}
		
		std::wstring m_ServiceName;
		std::wstring m_DisplayName;
		DWORD m_Type;
		EServiceState m_CurrentState;
		DWORD m_ProcessId;
	};
} // namespace model