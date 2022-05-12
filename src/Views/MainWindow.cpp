#include "MainWindow.h"
#include "../Controllers/Simulation.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  
  //menu
  act_=new QAction("Apri Cartella", this);
  connect(act_, SIGNAL(triggered()), this, SLOT(relayout()));
  fileMenu_ = menuBar()->addMenu("Simulazioni");
  fileMenu_->addAction(act_);
  //widget
  old_sim_=new OldSimulation(this);
  old_sim_->hide();
  container_ = new ContainerWidget(this);
  setCentralWidget(container_);
}

ContainerWidget *MainWindow::getContainerWidget() { return container_; }

void MainWindow::relayout(){
  container_->hide();

}