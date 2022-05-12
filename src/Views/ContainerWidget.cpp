#include "ContainerWidget.h"

ContainerWidget::ContainerWidget(QWidget *parent) : QWidget(parent) {
  //widget declaration
  old_sim_=new OldSimulation(this);
  input_widget_ = new InputWidget(this);
  simulation_ = new SimulationWidget(nullptr, this);
  //layout
  QHBoxLayout *layout = new QHBoxLayout(this);
  layout->addWidget(old_sim_);
  layout->addWidget(input_widget_);
  layout->addWidget(simulation_);
  simulation_->hide();
  old_sim_->hide();
  this->setLayout(layout);
}

InputWidget *ContainerWidget::getInputWidget() { return input_widget_; }

SimulationWidget *ContainerWidget::getSimulationWidget() { return simulation_; }

void ContainerWidget::setVisibleOldSim() {
  input_widget_->hide();
  simulation_->hide();
  old_sim_->show();
}

void ContainerWidget::setVisibleSimulator() {
  input_widget_->show();
  old_sim_->hide();
}