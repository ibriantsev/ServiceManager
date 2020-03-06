#include "ServiceTableController.h"

#include <vector>

namespace controller {
	ServiceTableController::ServiceTableController(view::ServiceTableView* const view)
	: m_ServiceTableView(view), m_ServiceManager() {
		m_ServiceManager.init();
	}
	void ServiceTableController::refresh(void) {
		m_ServiceTableView->clearTable();

		std::vector<model::ServiceInfo> serviceInfo;
		m_ServiceManager.enumerateServicesInfo(serviceInfo);

		for (auto& x : serviceInfo)
			m_ServiceTableView->addRow(x);
	}
} // namespace controller