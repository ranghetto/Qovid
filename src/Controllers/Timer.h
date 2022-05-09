#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QTimer>
#include "../Views/InputWidget.h"
#include "../Views/ClockWidget.h"

class Simulation;

class Timer: public QObject {
    Q_OBJECT
    public:
    Timer(Simulation*, InputWidget*, QObject *parent=nullptr);
    QString createQString(int, int);
    public slots:
        void updatetime();
        void start_timer();
        void stop_timer();
        void setInvisibleClock();
        void setVisibleClock();
    signals:
        void start();
        void resume();
    private:
    int sim_duration_;
    bool isRunning_;
    InputWidget *widget_;
    ClockWidget *clock_;
    QTimer update_;
    Simulation *simulation_;
};

#endif