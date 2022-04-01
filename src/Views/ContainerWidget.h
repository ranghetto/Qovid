#ifndef CONTAINERWIDGET_H
#define CONTAINERWIDGET_H

#include "InputWidget.h"
#include <QHBoxLayout>
#include <QWidget>

class Simulation;

class ContainerWidget : public QWidget {
  Q_OBJECT

public:
  ContainerWidget(QWidget *parent = nullptr);
  InputWidget* getInputWidget();
  void setSimulation(Simulation*);

private:
  InputWidget *input_widget_;
  Simulation* controller_;
};
#endif // CONTAINERWIDGET_H
