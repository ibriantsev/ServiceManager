#include "ServiceConstantConverter.h"

namespace com {
	HRESULT ServiceConstantConverter::convertServiceState(const ServiceManagement::ServiceState& in, EServiceState& out) {
		switch (in) {
		case ServiceManagement::ServiceState::Stopped:         out = Stopped;         return S_OK;
		case ServiceManagement::ServiceState::StartPending:    out = StartPending;    return S_OK;
		case ServiceManagement::ServiceState::StopPending:     out = StopPending;     return S_OK;
		case ServiceManagement::ServiceState::Running:         out = Running;         return S_OK;
		case ServiceManagement::ServiceState::ContinuePending: out = ContinuePending; return S_OK;
		case ServiceManagement::ServiceState::PausePending:    out = PausePending;    return S_OK;
		case ServiceManagement::ServiceState::Paused:          out = Paused;          return S_OK;
		default: return E_UNEXPECTED;
		}
	}
} // namespace com