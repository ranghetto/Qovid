#ifndef SIMULATION_H
#define SIMULATION_H

#include "../Entities/Entity.h"
#include "../Views/InputWidget.h"
#include "../Views/SimulationView.h"
#include "World.h"
#include <QElapsedTimer>
#include <QObject>
#include <QPainter>
#include <QTimer>
#include <QVector>
#include <QWidget>

class Simulation : QObject {
  Q_OBJECT

public:
  Simulation(QObject *parent = nullptr);

  // Setters
  void setView(SimulationView *view);
  void generateWorld();

  // Getters
  // TODO implement
  SimulationView *view() const;
  World *world() const;

  void render(QPainter &painter);

public slots:
  void update(); // update loop

private:
  // Views
  SimulationView *view_;
  InputWidget *input;

  // Controllers
  World *world_;

  // Members
  QTimer *loopTimer_;
  QElapsedTimer *deltaTimer_;
  bool isRunning_;
  qint64 lastTime_;

  void update(qint64 deltaTime);
};

#endif // SIMULATION_H