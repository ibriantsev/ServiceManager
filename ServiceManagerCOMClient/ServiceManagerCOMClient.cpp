#include <QApplication>

#include "ServiceTableView.h"
#include "ServiceTableController.h"

int main(int argc, char** argv) {
  int rc = 0;

  QApplication app(argc, argv);
  QWidget mainWindow;

  view::ServiceTableView* table = new view::ServiceTableView(&mainWindow);
  controller::ServiceTableController serviceTableController(table);
    
  serviceTableController.refresh();
  mainWindow.show();

  rc = app.exec();
  return rc;
}