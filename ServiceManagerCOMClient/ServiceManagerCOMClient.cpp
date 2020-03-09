#include <QApplication>
#include <QVBoxLayout>

#include "ServiceTableView.h"
#include "ServiceTableController.h"

int main(int argc, char** argv) {
  int rc = 0;

  QApplication app(argc, argv);
  QWidget mainWindow;
  mainWindow.setMinimumSize(800, 450);

  view::ServiceTableView* table = new view::ServiceTableView(&mainWindow);
  controller::ServiceTableController serviceTableController(table);

  QVBoxLayout* layout = new QVBoxLayout();
  layout->addWidget(table);
  mainWindow.setLayout(layout);

  serviceTableController.refresh();
  mainWindow.show();

  rc = app.exec();
  return rc;
}