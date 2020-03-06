#include "ServiceTableView.h"

#include <QVBoxLayout>

namespace view {
	ServiceTableView::ServiceTableView(QWidget* parent = 0): QWidget(parent) {

		m_ServiceTable = new QTableWidget(0, 3, this);

		QStringList labels;
		labels << tr("Name") << tr("Display name") << tr("PID");
		m_ServiceTable->setHorizontalHeaderLabels(labels);
		
		QVBoxLayout* layout = new QVBoxLayout;
		layout->addWidget(m_ServiceTable);

		setMinimumSize(450, 450);
		setLayout(layout);
	}
	void ServiceTableView::clearTable(void) {
		m_ServiceTable->setRowCount(0);
	}
	void ServiceTableView::addRow(const model::ServiceInfo& item) {
		int rowCnt = m_ServiceTable->rowCount();

		m_ServiceTable->setRowCount(rowCnt + 1);

		m_ServiceTable->setItem(rowCnt, 0, new QTableWidgetItem(QString::fromStdWString(item.m_ServiceName)));
		m_ServiceTable->setItem(rowCnt, 1, new QTableWidgetItem(QString::fromStdWString(item.m_DisplayName)));
		m_ServiceTable->setItem(rowCnt, 2, new QTableWidgetItem(QString::number(item.m_ProcessId)));
	}
} // namespace view