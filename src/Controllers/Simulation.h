#ifndef SIMULATION_H
#define SIMULATION_H

#include "../Entities/Entity.h"
#include "../Views/ContainerWidget.h"
#include "../Views/ClockWidget.h"
#include "../Views/InputWidget.h"
#include "../Views/MainWindow.h"
#include "../Views/SimulationWidget.h"
#include "World.h"
#include "Timer.h"
#include <QDir>
#include <QElapsedTimer>
#include <QFileDialog>
#include <QObject>
#include <QPainter>
#include <QTimer>
#include <QVector>
#include <QWidget>

class Simulation : public QObject {
  Q_OBJECT

public:
  Simulation(QObject *parent = nullptr);

  // Setters
  void setContainerWidgets(ContainerWidget *container);

  // Getters
  World *world() const;
  qint64 deltaTime() const;
  qint64 pausedTime() const;
  bool isRunning() const;

  // Called everytime view_ QWidget is updated();
  void render(QPainter &painter);

  // Helper functions
  void generateWorld();
  void generateTimer();

public slots:
  void update();          // main sim loop
  void startSimulation(); // handle InputWidget QPushButton
  void toggleSimulation();
  void stopSimulation();

signals:
  void simulationStarted();
  void simulationStopped();
  void simulationPaused();

private:
  // Views
  SimulationWidget *simulationWidget_;
  ContainerWidget *containerWidget_;
  InputWidget *inputWidget_;
  QFileDialog *save_simulation_;

  // Controllers
  World *world_;
  Timer *timer_;

  // Members
  QTimer *loopTimer_;
  QElapsedTimer *deltaTimer_;
  QElapsedTimer *pausedTimer_;
  qint64 lastTime_;
  qint64 deltaTime_;
  qint64 pausedTime_;

  void updateEntities(const Simulation &s);
  void connectSimulationStarted();
  void connectSimulationPaused();
  void connectSimulationStopped();
  void connectButtons();
};

#endif // SIMULATION_H
