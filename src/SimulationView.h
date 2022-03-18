#ifndef SIMULATION_VIEW_H
#define SIMULATION_VIEW_H

#include <QWidget>

class SimulationView : public QWidget {
  Q_OBJECT

public:
  SimulationView(QWidget *parent = 0);
  // void paintEvent(QPaintEvent *event);
};

#endif // SIMULATION_VIEW_H
