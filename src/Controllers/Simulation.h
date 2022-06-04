#ifndef SIMULATION_H
#define SIMULATION_H

#include "../Entities/Entity.h"
#include "../Loggers/ActorsLogger.h"
#include "../Views/ClockWidget.h"
#include "../Views/ContainerWidget.h"
#include "../Views/InputWidget.h"
#include "../Views/MainWindow.h"
#include "../Views/SimulationWidget.h"
#include "Timer.h"
#include "World.h"
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
  ~Simulation();

  // Setters
  void setContainerWidgets(ContainerWidget *container);

  // Getters
  World *world() const;
  ActorsLogger *logger() const;
  qint64 deltaTime() const;
  qint64 pausedTime() const;
  QElapsedTimer *durationTimer() const;
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
  void lineStart();
  void lineStop();

private:
  // Views
  ContainerWidget *containerWidget_;
  QFileDialog *saveSimulation_;

  // Controllers
  World *world_;
  Timer *timer_;

  // Loggers
  ActorsLogger *logger_;

  // Members
  QTimer *loopTimer_;
  QElapsedTimer *deltaTimer_;
  QElapsedTimer *pausedTimer_;
  qint64 lastTime_;
  qint64 deltaTime_;
  qint64 pausedTime_;
  QElapsedTimer *durationTimer_;

  void updateEntities();
  void connectSimulationStarted();
  void connectSimulationPaused();
  void connectSimulationStopped();
  void connectButtons();
};

#endif // SIMULATION_H
