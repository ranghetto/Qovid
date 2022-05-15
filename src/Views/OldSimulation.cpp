#include "OldSimulation.h"

OldSimulation::OldSimulation(QWidget *parent){
    list_=nullptr;
    f();
}

void OldSimulation::f(){
    list_=new QListWidget(this);
    new QListWidgetItem(tr("Oak"), list_);
    new QListWidgetItem(tr("Fir"), list_);
    new QListWidgetItem(tr("Pine"), list_);
}


