#include "SimulationWidget.h"
#include "../Controllers/Simulation.h"

SimulationWidget::SimulationWidget(Simulation *controller, QWidget *parent)
    : QWidget(parent), controller_(controller) {
  setFixedSize(500, 500);
  resize(500, 500);
}

void SimulationWidget::paintEvent(QPaintEvent *) {
  QPainter p(this);
  if (controller_)
    controller_->render(p);
}

void SimulationWidget::setController(Simulation *controller) {
  controller_ = controller;
}

void SimulationWidget::setVisibleSlot() { setVisible(true); }

void SimulationWidget::setInvisibleSlot() { setVisible(false); }