#include <QApplication>

#include "MainView.h"

int main(int argc, char** argv) {
  QApplication app(argc, argv);
  view::MainView mainView;
  mainView.show();
  return app.exec();
}