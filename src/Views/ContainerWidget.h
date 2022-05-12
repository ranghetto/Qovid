#ifndef CONTAINERWIDGET_H
#define CONTAINERWIDGET_H

#include "InputWidget.h"
#include "SimulationWidget.h"
#include <QHBoxLayout>
#include <QWidget>
#include "OldSimulation.h"

class Simulation;

class ContainerWidget : public QWidget {
  Q_OBJECT

public:
  ContainerWidget(QWidget *parent = nullptr);
  InputWidget *getInputWidget(); // return input_wiget to the controller
  SimulationWidget *getSimulationWidget();
public slots:
  void setVisibleOldSim();
  void setVisibleSimulator();
private:
  SimulationWidget *simulation_;
  InputWidget *input_widget_;
  OldSimulation *old_sim_;
};
#endif // CONTAINERWIDGET_H
