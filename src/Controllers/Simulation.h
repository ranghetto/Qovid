#ifndef SIMULATION_H
#define SIMULATION_H

#include "../Entities/Entity.h"
#include "../Views/ContainerWidget.h"
#include "../Views/InputWidget.h"
#include "../Views/MainWindow.h"
#include "../Views/SimulationView.h"
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
  void setView(SimulationView *view);
  void generateWorld();

  // Getters
  World *world() const;
  SimulationView *view() const; // TODO implement
  qint64 deltaTime() const;

  void render(QPainter &painter);

public slots:
  void update();                // update loop
  void handleStartSimulation(); // handle InputWidget QPushButton

private:
  // Private constructor, singleton pattern
  Simulation(QObject *parent = nullptr);
  static Simulation *instance_;

  // Views
  SimulationView *view_;
  MainWindow *main_window_;
  ContainerWidget *container_widget_;
  InputWidget *input_widget_;

  // Controllers
  World *world_;

  // Members
  QTimer *loopTimer_;
  QElapsedTimer *deltaTimer_;
  bool isRunning_;
  qint64 lastTime_;
  qint64 deltaTime_;

  void createMainWindow(); // setter for mainwindow, containerwidget,
                           // inputwidget

  void updateEntities();
};

#endif // SIMULATION_H
