#include "Simulation.h"

Simulation::Simulation(QObject *parent)
    : QObject(parent), world_(nullptr), loopTimer_(new QTimer(this)),
      deltaTimer_(new QElapsedTimer()), pausedTimer_(new QElapsedTimer()),
      pausedTime_(0) {

  connect(loopTimer_, SIGNAL(timeout()), this, SLOT(update()));
}

// SIGNAL & SLOTS
// handle signal from "start simulation" button
void Simulation::startSimulation() {

  emit simulationStarted();

  generateWorld();

  // ->start(0) is a timer configurations to enter in the event loop of Qt.
  // Every time `timeout()` signal is sent, the connecter slots'll be executed
  // in the main loop of Qt, without inferferring with normal operations.
  loopTimer_->start(0);

  // Timer to calculate `deltaTime`
  deltaTimer_->start();
  lastTime_ = deltaTimer_->elapsed();
}

// GETTERS
qint64 Simulation::deltaTime() const { return deltaTime_; }
World *Simulation::world() const { return world_; }
bool Simulation::isRunning() const { return loopTimer_->isActive(); };
qint64 Simulation::pausedTime() const { return pausedTime_; }

void Simulation::toggleSimulation() {
  emit simulationPaused();
  if (isRunning()) {
    loopTimer_->stop();
    pausedTimer_->start();
  } else {
    loopTimer_->start(0);
    deltaTimer_->restart();
    lastTime_ = deltaTimer_->elapsed();
    pausedTime_ += pausedTimer_->elapsed();
  }
};

// MAIN SIM LOOPS
void Simulation::update() {
  qint64 current = deltaTimer_->elapsed();
  qint64 elapsed = current - lastTime_;

  // input hanlder should be placed above if exists
  deltaTime_ = elapsed;
  updateEntities(*this);

  lastTime_ = current;
}

// HELPER METHODS
void Simulation::updateEntities(const Simulation &s) {
  if (world_)
    for (auto entity : world_->entities()) {
      if (entity)
        entity->update(s);
    }
}

void Simulation::render(QPainter &painter) {
  if (world_)
    for (auto entity : world_->entities()) {
      if (entity)
        entity->render(painter);
    }
}

void Simulation::setContainerWidgets(ContainerWidget *container) {
  containerWidget_ = container;
  inputWidget_ = container->getInputWidget();
  inputWidget_->setController(this);
  simulationWidget_ = container->getSimulationWidget();
  simulationWidget_->setController(this);
  timer_=inputWidget_->getClockWidget();


  connect(loopTimer_, SIGNAL(timeout()), simulationWidget_, SLOT(update()));

  connectButtons();

  connectSimulationStarted();
  connectSimulationPaused();
  connectSimulationStopped();
}

void Simulation::generateWorld() {
  world_ = new World(
      inputWidget_->getPopulation(), inputWidget_->getInfectionRange(),
      inputWidget_->getInfectionRate(), inputWidget_->getDeathRate(),
      inputWidget_->getTimeRecover(), inputWidget_->getInitialInfect());
}

void Simulation::connectSimulationStarted() {
  connect(this, SIGNAL(simulationStarted()), inputWidget_,
          SLOT(disableStartButton()));
  connect(this, SIGNAL(simulationStarted()), inputWidget_,
          SLOT(enablePauseButton()));
  connect(this, SIGNAL(simulationStarted()), inputWidget_,
          SLOT(enableStopButton()));
  connect(this, SIGNAL(simulationStarted()), simulationWidget_,
          SLOT(setVisibleSlot()));
  connect(this, SIGNAL(simulationStarted()), timer_,
          SLOT(setVisibleClock()));
}

void Simulation::connectSimulationStopped() {
  connect(this, SIGNAL(simulationStopped()), inputWidget_,
          SLOT(enableStartButton()));
  connect(this, SIGNAL(simulationStopped()), inputWidget_,
          SLOT(disablePauseButton()));
  connect(this, SIGNAL(simulationStopped()), inputWidget_,
          SLOT(disableStopButton()));
  connect(this, SIGNAL(simulationStopped()), timer_,
          SLOT(setInvisibleClock()));
}

void Simulation::connectSimulationPaused() {
  connect(this, SIGNAL(simulationPaused()), inputWidget_,
          SLOT(simulationPaused()));
  connect(this, SIGNAL(simulationPaused()), inputWidget_,
          SLOT(disableStartButton()));
  connect(this, SIGNAL(simulationPaused()), inputWidget_,
          SLOT(enableStopButton()));
  connect(this, SIGNAL(simulationPaused()), timer_,
          SLOT(stop_timer()));
}

void Simulation::connectButtons() {
  connect(inputWidget_->startSimButton(), SIGNAL(clicked()), this,
          SLOT(startSimulation()));
  connect(inputWidget_->pauseSimButton(), SIGNAL(clicked()), this,
          SLOT(toggleSimulation()));
  connect(inputWidget_->stopSimButton(), SIGNAL(clicked()), this,
          SLOT(stopSimulation()));
}

void Simulation::stopSimulation() {
  emit simulationStopped();
  loopTimer_->stop();
  delete world_;
}