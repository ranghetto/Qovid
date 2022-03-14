#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent){
    container=new ContainerWidget(this);
    setCentralWidget(container);
};
