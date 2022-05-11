#include "ContainerWidget.h"
#include "../Controllers/Simulation.h"

ContainerWidget::ContainerWidget(QWidget *parent) : QWidget(parent) {
  input_widget_ = new InputWidget(this);
  simulation_ = new SimulationWidget(nullptr, this);
  save_simulation_=nullptr;
  QHBoxLayout *layout = new QHBoxLayout(this);
  layout->addWidget(input_widget_);
  layout->addWidget(simulation_);
  simulation_->setVisible(false);
  this->setLayout(layout);
}

InputWidget *ContainerWidget::getInputWidget() { return input_widget_; }

SimulationWidget *ContainerWidget::getSimulationWidget() { return simulation_; }

bool ContainerWidget::SaveSimulationAlert(){
  save_simulation_=new QMessageBox(this);
  save_simulation_->setText("La simulazione è stata terminata");
  save_simulation_->setInformativeText("Vuoi salvare i dati?");
  save_simulation_->setStandardButtons(QMessageBox::Save | QMessageBox::Discard);
  save_simulation_->setDefaultButton(QMessageBox::Save);
  if(QMessageBox::Save == save_simulation_->exec())
  {return true;}
  else
  {return false;}
}
