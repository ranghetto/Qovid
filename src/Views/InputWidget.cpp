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
  label_recover = new QLabel(this);
  label_initial_infect = new QLabel(this);
  // input field
  input_population = new QSpinBox(this);
  input_infection_range = new QSpinBox(this);
  input_infection_rate = new QSpinBox(this);
  input_death_rate = new QSpinBox(this);
  input_time_toRecover = new QSpinBox(this);
  input_initial_infect = new QSpinBox(this);
  // button
  start_sim = new QPushButton("Inizia", this);
  pause_sim = new QPushButton("Pausa/Riprendi", this);
  pause_sim->setDisabled(true);
  stop_sim = new QPushButton("Stop", this);
  stop_sim->setDisabled(true);
  //timer
  clock_=new ClockWidget(this);
  // signal slot
  connect(input_population, SIGNAL(valueChanged(int)), this,
          SLOT(changeMax(int)));
  // label text
  label_population->setText("Grandezza della popolazione");
  label_infection_range->setText("Raggio del contagio");
  label_infection_rate->setText("Probabilità di essere contagiati");
  label_death_rate->setText("Probabilità di morte dell'infetto");
  label_recover->setText("Durata stato 'infetto'");
  label_initial_infect->setText("Infetti Iniziali");

  // SpinBox range setting
  input_population->setRange(0, 500);
  input_population->setValue(200);
  input_population->setSuffix(" persone");

  input_infection_range->setRange(0, 100);
  input_infection_range->setValue(2);
  input_infection_range->setSuffix(" metri");

  input_infection_rate->setRange(0, 100);
  input_infection_rate->setValue(15);
  input_infection_rate->setSuffix("%");

  input_death_rate->setRange(0, 100);
  input_death_rate->setValue(2);
  input_death_rate->setSuffix("%");

  input_time_toRecover->setRange(0, 50);
  input_time_toRecover->setValue(15);
  input_time_toRecover->setSuffix(" secondi");

  input_initial_infect->setValue(2);
  input_initial_infect->setSuffix(" persone");

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

  QHBoxLayout *btnLayout = new QHBoxLayout();

  btnLayout->addWidget(start_sim);
  btnLayout->addWidget(pause_sim);
  btnLayout->addWidget(stop_sim);

  layout->addSpacerItem(new QSpacerItem(0, 20));

  layout->addLayout(btnLayout);

  layout->addWidget(clock_);

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

ClockWidget* InputWidget::getClock() const {return clock_;}

void InputWidget::setController(Simulation *controller){ controller_=controller; };

int InputWidget::getPopulation() const { return input_population->value(); }

int InputWidget::getInfectionRange() const { return input_infection_range->value(); }

int InputWidget::getInfectionRate() const{ return input_infection_rate->value(); }

int InputWidget::getDeathRate() const{ return input_death_rate->value(); }

int InputWidget::getTimeRecover() const{ return input_time_toRecover->value(); }

int InputWidget::getInitialInfect() const{ return input_initial_infect->value(); }

QPushButton *InputWidget::startSimButton() const { return start_sim; }

QPushButton *InputWidget::pauseSimButton() const { return pause_sim; }

QPushButton *InputWidget::stopSimButton() const { return stop_sim; }