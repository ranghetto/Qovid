#ifndef CONTAINERWIDGET_H
#define CONTAINERWIDGET_H

#include "InputWidget.h"
#include "SimulationWidget.h"
#include <QHBoxLayout>
#include <QWidget>

class Simulation;

class ContainerWidget : public QWidget {
  Q_OBJECT

public:
  ContainerWidget(QWidget *parent = nullptr);
  InputWidget *getInputWidget();    // return input_wiget to the controller
  void setSimulation(Simulation *); // set controller_
  void addSimulationWidget(SimulationWidget *);

private:
  SimulationWidget *simulation_;
  InputWidget *input_widget_;
  Simulation *controller_;
};
#endif // CONTAINERWIDGET_H
