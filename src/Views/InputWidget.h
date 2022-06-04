#ifndef INPUTWIDGET_H
#define INPUTWIDGET_H

#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QWidget>
#include "ClockWidget.h"

class Simulation;

class InputWidget : public QWidget {
  Q_OBJECT
public:
  InputWidget(QWidget *parent = nullptr);
  // setters & getters
  void setController(Simulation *);
  ClockWidget* getClockWidget() const;
  int getPopulation() const;
  int getInfectionRange() const;
  int getInfectionRate() const;
  int getDeathRate() const;
  int getTimeRecover() const;
  int getInitialInfect() const;
  ClockWidget* getClock() const;

  QPushButton *startSimButton() const;
  QPushButton *pauseSimButton() const;
  QPushButton *stopSimButton() const;

public slots:
  void changeMax(int);
  void enablePauseButton();
  void enableStopButton();
  void enableStartButton();
  void disablePauseButton();
  void disableStopButton();
  void disableStartButton();

private:
  QLabel *label_population, *label_infection_range, *label_infection_rate,
      *label_death_rate, *label_recover, *label_initial_infect;
  QSpinBox *input_population, *input_infection_range, *input_infection_rate,
      *input_death_rate, *input_time_toRecover, *input_initial_infect;
  QPushButton *start_sim, *pause_sim, *stop_sim;
  ClockWidget *clock_;
  Simulation *controller_;
};

#endif // INPUTWIDGET_H
