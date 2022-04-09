#ifndef SIMULATION_H
#define SIMULATION_H

#include "../Entities/Entity.h"
#include "../Views/ContainerWidget.h"
#include "../Views/InputWidget.h"
#include "../Views/MainWindow.h"
#include "../Views/SimulationWidget.h"
#include "World.h"
#include <QElapsedTimer>
#include <QObject>
#include <QPainter>
#include <QTimer>
#include <QVector>
#include <QWidget>

class Simulation : public QObject {
  Q_OBJECT

public:
  static Simulation &instance();

  // Setters
  void setContainerAndInputWidget(ContainerWidget *container);

  // Getters
  World *world() const;
  qint64 deltaTime() const;
  bool isRunning() const;

  // Called everytime view_ QWidget is updated();
  void render(QPainter &painter);

  // Helper functions
  void generateWorld();
  void toggleSimulation() const;

public slots:
  void update();                // main sim loop
  void handleStartSimulation(); // handle InputWidget QPushButton

private:
  // Private constructor, singleton pattern
  Simulation(QObject *parent = nullptr);
  static Simulation *instance_;

  // Views
  SimulationWidget *simulationWidget_;
  ContainerWidget *containerWidget_;
  InputWidget *inputWidget_;

  // Controllers
  World *world_;

  // Members
  QTimer *loopTimer_;
  QElapsedTimer *deltaTimer_;
  bool isRunning_;
  qint64 lastTime_;
  qint64 deltaTime_;

  void updateEntities();
  void createSimulationWidgetAndAddToContainerLayout();
};

#endif // SIMULATION_H
