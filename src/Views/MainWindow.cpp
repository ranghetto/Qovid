#include "MainWindow.h"
#include "../Controllers/Simulation.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  container_ = new ContainerWidget(this);
  setCentralWidget(container_);
}

ContainerWidget *MainWindow::getContainerWidget() { return container_; }
