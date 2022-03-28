#ifndef SIMULATION_VIEW_H
#define SIMULATION_VIEW_H

class Simulation;
#include <QPainter>
#include <QWidget>

class SimulationView : public QWidget {
  Q_OBJECT

public:
  SimulationView(Simulation *controller = nullptr, QWidget *parent = 0);
  void paintEvent(QPaintEvent *) override;
  void setController(Simulation *controller);

private:
  Simulation *controller_;
};

#endif // SIMULATION_VIEW_H
