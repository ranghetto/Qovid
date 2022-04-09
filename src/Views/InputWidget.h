#ifndef INPUTWIDGET_H
#define INPUTWIDGET_H

#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QWidget>

class Simulation;

class InputWidget : public QWidget {
  Q_OBJECT
public:
  InputWidget(QWidget *parent = nullptr);
  // setters & getters
  void setSimulation(Simulation *);
  int getPopulation();
  int getInfectionRange();
  int getInfectionRate();
  int getDeathRate();
  int getTimeRecover();
  int getInitialInfect();

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
  void simulationPaused();

private:
  QLabel *label_population, *label_infection_range, *label_infection_rate,
      *label_death_rate, *label_time, *label_recover, *label_initial_infect;
  QSpinBox *input_population, *input_infection_range, *input_infection_rate,
      *input_death_rate, *input_time_toRecover, *input_initial_infect;
  QRadioButton *sim_duration_30s, *sim_duration_1m, *sim_duration_3m,
      *sim_duration_complete;
  QPushButton *start_sim, *pause_sim, *stop_sim;
  Simulation *controller_;
};

#endif // INPUTWIDGET_H
