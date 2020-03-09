#include "ServiceTableView.h"

#include <QVBoxLayout>
#include <QHeaderView>

#include "ServiceConstantConverter.h"
#include "ServiceTableItemFactory.h"

namespace view {
	ServiceTableView::ServiceTableView(QWidget* parent = 0): QWidget(parent) {
		m_ServiceTable = new QTableWidget(0, 5, this);
		
		QStringList labels;
		labels << "Name" << "Display name" << "Current State" << "PID" << "Type";
		m_ServiceTable->setHorizontalHeaderLabels(labels);
		m_ServiceTable->horizontalHeader()->setStretchLastSection(true);
		m_ServiceTable->verticalHeader()->setVisible(false);
		
		QVBoxLayout* layout = new QVBoxLayout;
		layout->addWidget(m_ServiceTable);
		setLayout(layout);
	}
	void ServiceTableView::clearTable(void) {
		m_ServiceTable->setRowCount(0);
	}
	void ServiceTableView::addRow(const model::ServiceInfo& item) {
		int rowCnt = m_ServiceTable->rowCount();
		
		m_ServiceTable->setRowCount(rowCnt + 1);
		
		m_ServiceTable->setItem(rowCnt, 0, ServiceTableItemFactory::createServiceTableItem(item.m_ServiceName, Qt::AlignCenter));
		m_ServiceTable->setItem(rowCnt, 1, ServiceTableItemFactory::createServiceTableItem(item.m_DisplayName, Qt::AlignVCenter));
		m_ServiceTable->setItem(rowCnt, 2, ServiceTableItemFactory::createServiceTableItem(ServiceConstantConverter::convertServiceStateToString(item.m_CurrentState), Qt::AlignCenter));
		m_ServiceTable->setItem(rowCnt, 3, ServiceTableItemFactory::createServiceTableItem(item.m_ProcessId, Qt::AlignCenter));
		m_ServiceTable->setItem(rowCnt, 4, ServiceTableItemFactory::createServiceTableItem(ServiceConstantConverter::convertServiceTypeToString(item.m_Type), Qt::AlignVCenter));
	}
} // namespace view