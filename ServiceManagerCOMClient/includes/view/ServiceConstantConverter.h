#pragma once

#include <QString>

#include "IServiceManager.h"

namespace view {
	class ServiceConstantConverter {
	public:
		static QString convertServiceTypeToString(ULONG type);
		static QString convertServiceStateToString(EServiceState state);
	};
} // namespace view