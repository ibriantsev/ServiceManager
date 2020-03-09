#pragma once

#include "IServiceManager.h"

#include <string>

namespace model {
	class ServiceConstantConverter {
	public:
		static std::wstring convertServiceTypeToString(ULONG type);
		static std::wstring convertServiceStateToString(EServiceState state);
	};
} // namespace view