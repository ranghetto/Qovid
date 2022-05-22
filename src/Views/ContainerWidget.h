#ifndef CONTAINERWIDGET_H
#define CONTAINERWIDGET_H

#include "InputWidget.h"
#include "SimulationWidget.h"
#include <QDebug>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QWidget>
#include "OldSimulation.h"

class Simulation;

class ContainerWidget : public QWidget {
  Q_OBJECT

public:
  ContainerWidget(QWidget *parent = nullptr);
  InputWidget *getInputWidget(); // return input_wiget to the controller
  SimulationWidget *getSimulationWidget();
  OldSimulation* getOldSimulation();
  void setController(Simulation*);
public slots:
  void setVisibleOldSim();
  void setVisibleSimulator();
  
  bool SaveSimulationAlert();

private:
  SimulationWidget *simulation_;
  InputWidget *input_widget_;
  QMessageBox *save_simulation_;
  OldSimulation *old_sim_;
  Simulation *controller_;

};
#endif // CONTAINERWIDGET_H
