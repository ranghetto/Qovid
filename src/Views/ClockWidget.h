#ifndef CLOCKWIDGET_H
#define CLOCKWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

class Timer;

class ClockWidget: public QWidget {
    Q_OBJECT
    public:
        ClockWidget(QWidget*);
        void setController(Timer*);
        void write(QString);
        void HideClock();
        void ShowClock();
    private:
        QLabel *label_;
        Timer *controller_;   
};

#endif