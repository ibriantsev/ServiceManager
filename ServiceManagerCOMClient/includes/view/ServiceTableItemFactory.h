#pragma once 

#include <string>
#include <QTableWidgetItem>

namespace view {
	class ServiceTableItemFactory {
	public:
		static QTableWidgetItem* createServiceTableItem(const std::wstring& text, Qt::AlignmentFlag alignment);
		static QTableWidgetItem* createServiceTableItem(unsigned long number, Qt::AlignmentFlag alignment);
	};
}