#include "ContainerWidget.h"
#include "../Controllers/Simulation.h"

ContainerWidget::ContainerWidget(QWidget *parent) : QWidget(parent) {
  input_widget_ = new InputWidget(this);
  simulation_ = new SimulationWidget(nullptr, this);
  QHBoxLayout *layout = new QHBoxLayout(this);
  layout->addWidget(input_widget_);
  layout->addWidget(simulation_);
  simulation_->setVisible(false);
  this->setLayout(layout);
}

InputWidget *ContainerWidget::getInputWidget() { return input_widget_; }

SimulationWidget *ContainerWidget::getSimulationWidget() { return simulation_; }
