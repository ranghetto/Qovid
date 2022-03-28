#include "ContainerWidget.h"

ContainerWidget::ContainerWidget(QWidget *parent) {
  input_widget = new InputWidget(this);
  sim = new SimulationView(nullptr, this);
  QHBoxLayout *layout = new QHBoxLayout(this);
  layout->addWidget(input_widget);
  layout->addWidget(sim);
  this->setLayout(layout);
}
