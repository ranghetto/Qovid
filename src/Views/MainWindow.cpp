#include "MainWindow.h"
#include "../Controllers/Simulation.h"

MainWindow::MainWindow(QWidget *parent){
    container=new ContainerWidget(this);
    setCentralWidget(container);
}

void MainWindow::setSimulation(Simulation* controller){
    controller_=controller;
}

ContainerWidget* MainWindow::getContainer(){
    return container;
}
