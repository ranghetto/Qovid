#include "ViewController.h"

ViewController::ViewController(QObject *parent): main_window_(new MainWindow), sim_controller(new Simulation){}

void ViewController::show(){
    main_window_->show();
}
