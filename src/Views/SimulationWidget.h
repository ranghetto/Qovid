#ifndef SIMULATION_WIDGET_H
#define SIMULATION_WIDGET_H

class Simulation;
#include <QPainter>
#include <QWidget>

class SimulationWidget : public QWidget {
  Q_OBJECT

public:
  SimulationWidget(Simulation *controller = nullptr, QWidget *parent = 0);
  void paintEvent(QPaintEvent *) override;
  void setController(Simulation *controller);

private:
  Simulation *controller_;

public slots:
  void setVisibleSlot();
  void setInvisibleSlot();
};

#endif // SIMULATION_WIDGET_H
