#include "ViewController.h"

ViewController::ViewController(QObject *parent):main_window_(new MainWindow){}

void ViewController::show(){
    main_window_->show();
}
