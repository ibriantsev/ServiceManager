#include "ServiceTableItemFactory.h"

#include <QString>

namespace view {
	QTableWidgetItem* ServiceTableItemFactory::createServiceTableItem(const std::wstring& text, Qt::AlignmentFlag alignment) {
		QTableWidgetItem* item = new QTableWidgetItem(QString::fromStdWString(text));
		item->setTextAlignment(alignment);
		return item;
	}
	QTableWidgetItem* ServiceTableItemFactory::createServiceTableItem(unsigned long number, Qt::AlignmentFlag alignment) {
		QTableWidgetItem* item = new QTableWidgetItem(QString::number(number));
		item->setTextAlignment(alignment);
		return item;
	}
} // namespace view