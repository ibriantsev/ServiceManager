#pragma once

#include <QTableWidget>

#include "ServiceInfo.h"

namespace view {
	class ServiceTableView : public QWidget {
	public:
		explicit ServiceTableView(QWidget* parent);
		
		void clearTable(void);
		void addRow(const model::ServiceInfo& item);
	private:
		QTableWidget* m_ServiceTable;
	};
} // namespace view