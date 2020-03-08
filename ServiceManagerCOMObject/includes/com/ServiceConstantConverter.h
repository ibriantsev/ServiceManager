#pragma once

#include "ServiceConstants.h"
#include "IServiceManager.h"

namespace com {
	class ServiceConstantConverter {
	public:
		static HRESULT convertServiceState(const ServiceManagement::ServiceState& in, EServiceState& out);
	};
} // namespace com