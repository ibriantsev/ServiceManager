#pragma once

#include <objbase.h>

#include "Service.h"

namespace com {
	class ServiceInfoConverter{
	public:
		static HRESULT convertToVariant(const ServiceManagement::ServiceInfo& serviceInfo, VARIANT& variant);
	};
} // namespace com