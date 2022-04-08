#include "ContainerWidget.h"
#include "../Controllers/Simulation.h"

ContainerWidget::ContainerWidget(QWidget *parent) {
  input_widget_ = new InputWidget(this);
  QHBoxLayout *layout = new QHBoxLayout(this);
  layout->addWidget(input_widget_);
  this->setLayout(layout);
}

//setter & getter

void ContainerWidget::setSimulation(Simulation* controller){
    controller_=controller;
}

InputWidget* ContainerWidget::getInputWidget(){
    return input_widget_;
}

//function

void ContainerWidget::addSimulationView(SimulationView *simulation){
    simulation_=simulation;
    layout()->addWidget(simulation_);
}
