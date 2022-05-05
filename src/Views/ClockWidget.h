#ifndef CLOCKWIDGET_H
#define CLOCKWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QDebug>

class Simulation;

class ClockWidget: public QWidget {
    Q_OBJECT
    public:
        ClockWidget(QWidget*);
        void setSimulation(Simulation*);
        QString createQString();
    public slots:
        void updatetime();
        void start_timer();
        void stop_timer();
        void setVisibleClock();
        void setInvisibleClock();
        void fine();
    signals:
        void start();
        void resume();
    private:
        int temp;
        bool isRunning;
        QLabel *label_;
        QTimer sim_timer_, update_; 
        Simulation *controller_;   
};

#endif