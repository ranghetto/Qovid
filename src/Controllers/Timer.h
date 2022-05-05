#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include "../Views/InputWidget.h"
#include "../Views/ClockWidget.h"

class Simulation;

class Timer: public QObject {
    Q_OBJECT
    public:
    Timer(InputWidget*, QObject *parent=nullptr);
    QString createQString(int, int);
    public slots:
        void updatetime();
        void start_timer();
        void stop_timer();
        void setVisibleClock();
        void setInvisibleClock();
    signals:
        void start();
        void resume();
    private:
    int sim_duration_, temp_;
    bool isRunning_, isUntillEnd_;
    InputWidget *widget_;
    ClockWidget *clock_;
    QTimer sim_timer_, update_;
};

#endif