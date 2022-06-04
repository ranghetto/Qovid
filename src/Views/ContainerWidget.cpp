#include "ContainerWidget.h"
#include "../Controllers/Simulation.h"

ContainerWidget::ContainerWidget(QWidget *parent) : QWidget(parent) {
  // widget declaration
  old_sim_ = new OldSimulation(this);
  input_widget_ = new InputWidget(this);
  simulation_ = new SimulationWidget(nullptr, this);
  // layout
  save_simulation_ = nullptr;
  QHBoxLayout *layout = new QHBoxLayout(this);
  layout->addWidget(old_sim_);
  layout->addWidget(input_widget_);
  layout->addWidget(simulation_);
  simulation_->hide();
  old_sim_->hide();
  setLayout(layout);
}

void ContainerWidget::setController(Simulation *controller) {
  controller_ = controller;
}

InputWidget *ContainerWidget::getInputWidget() const { return input_widget_; }

SimulationWidget *ContainerWidget::getSimulationWidget() const { return simulation_; }

OldSimulation *ContainerWidget::getOldSimulation() const { return old_sim_; }

void ContainerWidget::setVisibleOldSim() {
  if (controller_->isRunning()) {
    controller_->toggleSimulation();
  }
  input_widget_->hide();
  simulation_->hide();
  old_sim_->show();
}

void ContainerWidget::setVisibleSimulator() {
  if (controller_->world() != nullptr) {
    simulation_->show();
  }
  input_widget_->show();
  old_sim_->hide();
}

bool ContainerWidget::SaveSimulationAlert() {
  save_simulation_ = new QMessageBox(this);
  save_simulation_->setText("La simulazione è stata terminata");
  save_simulation_->setInformativeText("Vuoi salvare i dati?");
  save_simulation_->setStandardButtons(QMessageBox::Save |
                                       QMessageBox::Discard);
  save_simulation_->setDefaultButton(QMessageBox::Save);
  if (QMessageBox::Save == save_simulation_->exec()) {
    return true;
  } else {
    return false;
  }
}