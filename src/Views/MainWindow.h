#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ContainerWidget.h"
#include <QMainWindow>
#include <QWidget>
#include <QMenu>
#include <QMenuBar>
#include <QAction>

class Simulation;

class MainWindow : public QMainWindow {
  Q_OBJECT
public:
  MainWindow(QWidget *parent = nullptr);
  ContainerWidget *getContainerWidget();
private:
  ContainerWidget *container_;
  QAction *sim_, *old_sim_;
  QMenu *fileMenu_;
};

#endif
