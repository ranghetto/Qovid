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
    Timer(Simulation*, InputWidget*);
    QString createQString(int, int) const;
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
    Simulation *simulation_;
    InputWidget *widget_;
    ClockWidget *clock_;
    QTimer *update_;
};

#endif