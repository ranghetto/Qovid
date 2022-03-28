#include "InputWidget.h"

InputWidget::InputWidget(QWidget *parent) : QWidget(parent) {
  // variables declaration and inizialization
  // layout
  QVBoxLayout *layout = new QVBoxLayout(this);
  // label
  label_population = new QLabel(this);
  label_infection = new QLabel(this);
  label_infection_rate = new QLabel(this);
  label_death_rate = new QLabel(this);
  label_time = new QLabel(this);
  // input field
  input_population = new QSpinBox(this);
  input_infection = new QSpinBox(this);
  input_infection_rate = new QSpinBox(this);
  input_death_rate = new QSpinBox(this);
  // radio menu
  sim_duration_30s = new QRadioButton("30 secondi", this);
  sim_duration_1m = new QRadioButton("1 minuto", this);
  sim_duration_3m = new QRadioButton("3 minuto", this);
  sim_duration_complete = new QRadioButton("fino al completamento", this);
  // button
  start_sim = new QPushButton("Inizia Simulazione", this);
  // label text
  label_population->setText("Grandezza della popolazione");
  label_infection->setText("Raggio del contagio");
  label_infection_rate->setText("Probabilità di essere contagiati");
  label_death_rate->setText("Probabilità di morte dell'infetto");
  label_time->setText("Durata simulazione");
  // SpinBox max min setting
  input_population->setMaximum(100);
  input_population->setMinimum(0);
  input_infection->setMaximum(100);
  input_infection->setMinimum(0);
  input_infection_rate->setMaximum(100);
  input_infection_rate->setMinimum(0);
  input_death_rate->setMaximum(100);
  input_death_rate->setMinimum(0);
  // adding widget to layout
  layout->addWidget(label_population);
  layout->addWidget(input_population);
  layout->addWidget(label_infection);
  layout->addWidget(input_infection);
  layout->addWidget(label_infection_rate);
  layout->addWidget(input_infection_rate);
  layout->addWidget(label_death_rate);
  layout->addWidget(input_death_rate);
  layout->addWidget(label_time);
  layout->addWidget(sim_duration_30s);
  layout->addWidget(sim_duration_1m);
  layout->addWidget(sim_duration_3m);
  layout->addWidget(sim_duration_complete);
  layout->addWidget(start_sim);

  this->setLayout(layout);
}
