#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ContainerWidget.h"
#include <QMainWindow>
#include <QWidget>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include "OldSimulation.h"
//TODO remove after tests
#include <QDebug>

class Simulation;

class MainWindow : public QMainWindow {
  Q_OBJECT
public:
  MainWindow(QWidget *parent = nullptr);
  ContainerWidget *getContainerWidget();
public slots:
  void relayout();
private:
  ContainerWidget *container_;
  QAction *act_;
  QMenu *fileMenu_;
  OldSimulation *old_sim_;
};

#endif
