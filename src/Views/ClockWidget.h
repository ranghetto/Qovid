#ifndef CLOCKWIDGET_H
#define CLOCKWIDGET_H

#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>

class Timer;

class ClockWidget : public QWidget {
  Q_OBJECT
public:
  ClockWidget(QWidget *);
  void setController(Timer *);
  void write(QString);
  void HideClock();
  void ShowClock();

private:
  QLabel *label_;
  Timer *controller_;
};

#endif