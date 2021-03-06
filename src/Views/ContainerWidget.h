#ifndef CONTAINERWIDGET_H
#define CONTAINERWIDGET_H

#include "InputWidget.h"
#include "SimulationWidget.h"
#include <QHBoxLayout>
#include <QMessageBox>
#include <QWidget>
#include "OldSimulation.h"
#include "Charts/LineChart.h" 
#include <QChartView>

class Simulation;

class ContainerWidget : public QWidget {
  Q_OBJECT

public:
  ContainerWidget(QWidget *parent = nullptr);
  InputWidget *getInputWidget() const; // return input_wiget to the controller
  SimulationWidget *getSimulationWidget() const;
  OldSimulation* getOldSimulation() const;
  void setController(Simulation*);
  void createGraph(LineChart*);
  void setInvisibleChart();

public slots:
  void setVisibleOldSim();
  void setVisibleSimulator();
  bool SaveSimulationAlert();

private:
  QHBoxLayout *layout;
  QtCharts::QChartView *chart_view_;
  SimulationWidget *simulation_;
  InputWidget *input_widget_;
  QMessageBox *save_simulation_;
  OldSimulation *old_sim_;
  Simulation *controller_;

};
#endif // CONTAINERWIDGET_H
