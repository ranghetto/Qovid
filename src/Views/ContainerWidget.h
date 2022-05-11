#ifndef CONTAINERWIDGET_H
#define CONTAINERWIDGET_H

#include "InputWidget.h"
#include "SimulationWidget.h"
#include <QHBoxLayout>
#include <QWidget>
#include <QMessageBox>
#include <QDebug>

class Simulation;

class ContainerWidget : public QWidget {
  Q_OBJECT

public:
  ContainerWidget(QWidget *parent = nullptr);
  InputWidget *getInputWidget(); // return input_wiget to the controller
  SimulationWidget *getSimulationWidget();
  bool SaveSimulationAlert();

private:
  SimulationWidget *simulation_;
  InputWidget *input_widget_;
  QMessageBox *save_simulation_;
  };
#endif // CONTAINERWIDGET_H
