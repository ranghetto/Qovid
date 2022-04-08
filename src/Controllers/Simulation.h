#ifndef SIMULATION_H
#define SIMULATION_H

#include "../Views/MainWindow.h"
#include "../Views/ContainerWidget.h"
#include "../Views/InputWidget.h"
#include "../Views/SimulationView.h"
#include "../Entities/Entity.h"
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
  void setMainWindow(); //setter for mainwindow, containerwidget, inputwidget
  void setView(SimulationView *view);
  void generateWorld();

  // Getters
  World *world() const;
  SimulationView *view() const; // TODO implement

  void render(QPainter &painter);

public slots:
  void update(); // update loop
  void handleStartSimulation(); //handle InputWidget QPushButton

private:
  // Private constructor, singleton pattern
  Simulation(QObject *parent = nullptr);
  static Simulation *instance_;

  // Views
  SimulationView *view_;
  MainWindow *main_window_;
  ContainerWidget* container_widget_;
  InputWidget *input_widget_;

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
