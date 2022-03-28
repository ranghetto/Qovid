#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ContainerWidget.h"
#include <QMainWindow>
#include <QWidget>

class MainWindow : public QMainWindow {
  Q_OBJECT
protected:
  ContainerWidget *container;

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow() = default;
};

#endif
