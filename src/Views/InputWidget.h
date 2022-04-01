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
    void setSimulation(Simulation*);
private:
  QLabel *label_population, *label_infection, *label_infection_rate,
      *label_death_rate, *label_time;
  QSpinBox *input_population, *input_infection, *input_infection_rate,
      *input_death_rate;
  QRadioButton *sim_duration_30s, *sim_duration_1m, *sim_duration_3m,
      *sim_duration_complete;
  QPushButton *start_sim;
  Simulation *controller_;
};



#endif // INPUTWIDGET_H
