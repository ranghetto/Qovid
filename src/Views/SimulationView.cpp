#include "SimulationView.h"
#include "../Controllers/Simulation.h"

SimulationView::SimulationView(Simulation *controller, QWidget *parent)
    : QWidget(parent), controller_(controller) {
  setFixedSize(500, 500);
  resize(500, 500);
}

void SimulationView::paintEvent(QPaintEvent *) {
  QPainter p(this);
  if (controller_)
    controller_->render(p);
}

void SimulationView::setController(Simulation *controller) {
  controller_ = controller;
}