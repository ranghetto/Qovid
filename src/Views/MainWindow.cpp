#include "MainWindow.h"
#include "../Controllers/Simulation.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  
  //menu
  old_sim_=new QAction("Apri Cartella", this);
  sim_=new QAction("Apri Simulatore", this);
  fileMenu_ = menuBar()->addMenu("Simulazioni");
  fileMenu_->addAction(old_sim_);
  fileMenu_->addAction(sim_);
  //central widget
  container_ = new ContainerWidget(this);
  setCentralWidget(container_);
  
  connect(old_sim_, SIGNAL(triggered()), container_, SLOT(setVisibleOldSim()));
  connect(sim_, SIGNAL(triggered()), container_, SLOT(setVisibleSimulator()));
}

ContainerWidget *MainWindow::getContainerWidget() const { return container_; }

