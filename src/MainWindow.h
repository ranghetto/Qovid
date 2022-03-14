#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include "containerwidget.h"

class MainWindow: public QMainWindow
{
    Q_OBJECT
    protected:
        ContainerWidget* container;

    public:
        MainWindow(QWidget *parent=nullptr);
        ~MainWindow()=default;
};

#endif
