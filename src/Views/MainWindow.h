#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ContainerWidget.h"
#include <QMainWindow>
#include <QWidget>

class Simulation;

class MainWindow : public QMainWindow {
  Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ContainerWidget* getContainer();
    void setSimulation(Simulation*);
private:
  ContainerWidget *container;
  Simulation* controller_;
};

#endif
