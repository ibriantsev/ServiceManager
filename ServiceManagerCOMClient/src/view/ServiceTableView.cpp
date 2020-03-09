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
		m_ServiceTable->setSortingEnabled(true);
		
		m_ServiceTable->verticalHeader()->setVisible(false);
		m_ServiceTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
		
		QVBoxLayout* layout = new QVBoxLayout;
		layout->addWidget(m_ServiceTable);
		setLayout(layout);
	}
	void ServiceTableView::clearTable(void) {
		m_ServiceTable->setRowCount(0);
	}
	void ServiceTableView::addRow(const model::ServiceInfo& item) {
		m_ServiceTable->setSortingEnabled(false);

		int rowCnt = m_ServiceTable->rowCount();
		m_ServiceTable->setRowCount(rowCnt + 1);
		
		std::wstring serviceStateWStr = model::ServiceConstantConverter::convertServiceStateToString(item.m_CurrentState);
		std::wstring serviceTypeWStr = model::ServiceConstantConverter::convertServiceTypeToString(item.m_Type);
		
		m_ServiceTable->setItem(rowCnt, 0, ServiceTableItemFactory::createServiceTableItem(item.m_ServiceName, Qt::AlignCenter));
		m_ServiceTable->setItem(rowCnt, 1, ServiceTableItemFactory::createServiceTableItem(item.m_DisplayName, Qt::AlignVCenter));
		m_ServiceTable->setItem(rowCnt, 2, ServiceTableItemFactory::createServiceTableItem(serviceStateWStr, Qt::AlignCenter));
		m_ServiceTable->setItem(rowCnt, 3, ServiceTableItemFactory::createServiceTableItem(item.m_ProcessId, Qt::AlignCenter));
		m_ServiceTable->setItem(rowCnt, 4, ServiceTableItemFactory::createServiceTableItem(serviceTypeWStr, Qt::AlignVCenter));

		m_ServiceTable->setSortingEnabled(true);
	}
} // namespace view