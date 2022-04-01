#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H
#include <QObject>
#include "../Views/MainWindow.h"
#include "Simulation.h"

class ViewController: public QObject
{
    Q_OBJECT
    public:
        ViewController(QObject *parent = nullptr);
        virtual ~ViewController(){};
        void show();
    private:
        MainWindow *main_window_;
        Simulation *sim_controller;
};

#endif // VIEWCONTROLLER_H
