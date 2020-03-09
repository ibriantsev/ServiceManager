#include "ServiceTableController.h"

#include <vector>
#include <QSortFilterProxyModel>

namespace controller {
	ServiceTableController::ServiceTableController(model::ServiceTableModel* const model, 
																								 view::ServiceTableView* const view)
	: m_ServiceTableModel(model), m_ServiceTableView(view), m_ServiceManager() {
		m_ServiceManager.init();
		
		QSortFilterProxyModel* proxyModel = new QSortFilterProxyModel(model); // create proxy
		proxyModel->setSourceModel(model);
		
		view->setModel(proxyModel);
	}
	void ServiceTableController::refresh(void) {
		std::vector<model::ServiceInfo> serviceInfo;
		m_ServiceManager.enumerateServicesInfo(serviceInfo);
		m_ServiceTableModel->setData(serviceInfo);
	}
} // namespace controller