#include "InputWidget.h"
#include "../Controllers/Simulation.h"

InputWidget::InputWidget(QWidget *parent) : QWidget(parent) {
  // variables declaration and inizialization
  // layout
  QVBoxLayout *layout = new QVBoxLayout(this);
  // label
  label_population = new QLabel(this);
  label_infection_range = new QLabel(this);
  label_infection_rate = new QLabel(this);
  label_death_rate = new QLabel(this);
  label_time = new QLabel(this);
  label_recover = new QLabel(this);
  label_initial_infect = new QLabel(this);
  // input field
  input_population = new QSpinBox(this);
  input_infection_range = new QSpinBox(this);
  input_infection_rate = new QSpinBox(this);
  input_death_rate = new QSpinBox(this);
  input_time_toRecover = new QSpinBox(this);
  input_initial_infect = new QSpinBox(this);
  // radio menu
  sim_duration_30s = new QRadioButton("30 secondi", this);
  sim_duration_1m = new QRadioButton("1 minuto", this);
  sim_duration_3m = new QRadioButton("3 minuto", this);
  sim_duration_complete = new QRadioButton("fino al completamento", this);
  // button
  start_sim = new QPushButton("Inizia", this);
  pause_sim = new QPushButton("Pausa/Riprendi", this);
  pause_sim->setDisabled(true);
  stop_sim = new QPushButton("Stop", this);
  stop_sim->setDisabled(true);
  // signal slot
  connect(input_population, SIGNAL(valueChanged(int)), this,
          SLOT(changeMax(int)));
  // label text
  label_population->setText("Grandezza della popolazione");
  label_infection_range->setText("Raggio del contagio");
  label_infection_rate->setText("Probabilità di essere contagiati");
  label_death_rate->setText("Probabilità di morte dell'infetto");
  label_time->setText("Durata simulazione");
  label_recover->setText("Durata infezione");
  label_initial_infect->setText("Infetti Iniziali");

  // SpinBox range setting
  input_population->setRange(0, 500);
  input_population->setValue(200);

  input_infection_range->setRange(0, 100);
  input_infection_range->setValue(2);

  input_infection_rate->setRange(0, 100);
  input_infection_rate->setValue(15);

  input_death_rate->setRange(0, 100);
  input_death_rate->setValue(2);

  input_time_toRecover->setRange(0, 60000);
  input_time_toRecover->setValue(20000);

  input_initial_infect->setValue(2);

  // adding widget to layout
  layout->addWidget(label_population);
  layout->addWidget(input_population);
  layout->addWidget(label_infection_range);
  layout->addWidget(input_infection_range);
  layout->addWidget(label_infection_rate);
  layout->addWidget(input_infection_rate);
  layout->addWidget(label_death_rate);
  layout->addWidget(input_death_rate);
  layout->addWidget(label_recover);
  layout->addWidget(input_time_toRecover);
  layout->addWidget(label_initial_infect);
  layout->addWidget(input_initial_infect);
  layout->addWidget(label_time);
  layout->addWidget(sim_duration_30s);
  layout->addWidget(sim_duration_1m);
  layout->addWidget(sim_duration_3m);
  layout->addWidget(sim_duration_complete);

  QHBoxLayout *btnLayout = new QHBoxLayout();

  btnLayout->addWidget(start_sim);
  btnLayout->addWidget(pause_sim);
  btnLayout->addWidget(stop_sim);

  layout->addSpacerItem(new QSpacerItem(0, 20));

  layout->addLayout(btnLayout);

  this->setLayout(layout);
}

void InputWidget::disableStartButton() { start_sim->setDisabled(true); }
void InputWidget::disablePauseButton() { pause_sim->setDisabled(true); }
void InputWidget::disableStopButton() { stop_sim->setDisabled(true); }
void InputWidget::enableStartButton() { start_sim->setEnabled(true); }
void InputWidget::enablePauseButton() { pause_sim->setEnabled(true); }
void InputWidget::enableStopButton() { stop_sim->setEnabled(true); }
void InputWidget::simulationPaused() {}

void InputWidget::changeMax(int n) { input_initial_infect->setMaximum(n); }

// setters & getters

void InputWidget::setSimulation(Simulation *controller) {
  controller_ = controller;
}

int InputWidget::getPopulation() { return input_population->value(); }

int InputWidget::getInfectionRange() { return input_infection_range->value(); }

int InputWidget::getInfectionRate() { return input_infection_rate->value(); }

int InputWidget::getDeathRate() { return input_death_rate->value(); }

int InputWidget::getTimeRecover() { return input_time_toRecover->value(); }

int InputWidget::getInitialInfect() { return input_initial_infect->value(); }

QPushButton *InputWidget::startSimButton() const { return start_sim; }

QPushButton *InputWidget::pauseSimButton() const { return pause_sim; }

QPushButton *InputWidget::stopSimButton() const { return stop_sim; }