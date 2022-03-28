#ifndef CONTAINERWIDGET_H
#define CONTAINERWIDGET_H

#include "InputWidget.h"
#include "SimulationView.h"
#include <QHBoxLayout>
#include <QWidget>

class ContainerWidget : public QWidget {
  Q_OBJECT
private:
  InputWidget *input_widget;
  SimulationView *sim;

public:
  ContainerWidget(QWidget *parent = nullptr);
  ~ContainerWidget() = default;
};

#endif // CONTAINERWIDGET_H
