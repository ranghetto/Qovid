#ifndef CLOCKWIDGET_H
#define CLOCKWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>

class Simulation;

class ClockWidget: public QWidget {
    Q_OBJECT
    public:
        ClockWidget(QWidget*);
        void setSimulation(Simulation*);
    public slots:
        void updatetime();
        void start();
        void setVisibleClock();
        void setInvisibleClock();
    signals:
        void start_timer();
    private:
        QLabel *label_;
        QTime start_time_;
        QTimer timer_; 
        Simulation *controller_;   
};

#endif