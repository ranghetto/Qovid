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
  // input field
  input_population = new QSpinBox(this);
  input_infection_range = new QSpinBox(this);
  input_infection_rate = new QSpinBox(this);
  input_death_rate = new QSpinBox(this);
  input_time_toRecover = new QSpinBox(this);
  // radio menu
  sim_duration_30s = new QRadioButton("30 secondi", this);
  sim_duration_1m = new QRadioButton("1 minuto", this);
  sim_duration_3m = new QRadioButton("3 minuto", this);
  sim_duration_complete = new QRadioButton("fino al completamento", this);
  // button
  start_sim = new QPushButton("Inizia Simulazione", this);
  // label text
  label_population->setText("Grandezza della popolazione");
  label_infection_range->setText("Raggio del contagio");
  label_infection_rate->setText("Probabilità di essere contagiati");
  label_death_rate->setText("Probabilità di morte dell'infetto");
  label_time->setText("Durata simulazione");
  label_recover->setText("Durata infezione");
  // SpinBox max min setting
  input_population->setMaximum(300);
  input_population->setMinimum(2);
  input_infection_range->setMaximum(100);
  input_infection_range->setMinimum(0);
  input_infection_rate->setMaximum(100);
  input_infection_rate->setMinimum(0);
  input_death_rate->setMaximum(100);
  input_death_rate->setMinimum(0);
  input_time_toRecover->setMaximum(10000);
  input_time_toRecover->setMinimum(500);
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
  layout->addWidget(label_time);
  layout->addWidget(sim_duration_30s);
  layout->addWidget(sim_duration_1m);
  layout->addWidget(sim_duration_3m);
  layout->addWidget(sim_duration_complete);
  layout->addWidget(start_sim);

  this->setLayout(layout);
}

void InputWidget::disableSimulationButton(){
  start_sim->setEnabled(false);
}

//setters & getters

void InputWidget::setSimulation(Simulation *controller){
    controller_=controller;
    connect(start_sim, SIGNAL(clicked()), controller_, SLOT(handleStartSimulation()));
}

int InputWidget::getPopulation(){
  return input_population->value();
}

int InputWidget::getInfectionRange(){
  return input_infection_range->value();
}

int InputWidget::getInfectionRate(){
  return input_infection_rate->value();
}

int InputWidget::getDeathRate(){
  return input_death_rate->value();
}

int InputWidget::getTimeRecover(){
  return input_time_toRecover->value();
}



