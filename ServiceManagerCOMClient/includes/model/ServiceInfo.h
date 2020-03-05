#pragma once 

#include <string>

namespace model {
	struct ServiceInfo {
		ServiceInfo(const std::wstring& serviceName,
								const std::wstring& displayName,
								unsigned long processId)
		: m_ServiceName(serviceName), m_DisplayName(displayName), m_ProcessId(processId) {
		}

		std::wstring m_ServiceName;
		std::wstring m_DisplayName;
		unsigned long m_ProcessId;
	};
} // namespace model