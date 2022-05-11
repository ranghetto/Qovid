#include "Simulation.h"
#include <QString>

Simulation::Simulation(QObject *parent)
    : QObject(parent), world_(nullptr), loopTimer_(new QTimer(this)),
      deltaTimer_(new QElapsedTimer()), pausedTimer_(new QElapsedTimer()),
      pausedTime_(0), durationTimer_(new QElapsedTimer()) {

  connect(loopTimer_, SIGNAL(timeout()), this, SLOT(update()));
}

ActorsLogger *Simulation::logger() const { return logger_; }

// SIGNAL & SLOTS
// handle signal from "start simulation" button
void Simulation::startSimulation() {

  generateWorld();
  generateTimer();

  emit simulationStarted();
  // ->start(0) is a timer configurations to enter in the event loop of Qt.
  // Every time `timeout()` signal is sent, the connecter slots'll be executed
  // in the main loop of Qt, without inferferring with normal operations.
  loopTimer_->start(0);
  durationTimer_->start();

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
  updateEntities();

  lastTime_ = current;
}

// HELPER METHODS
void Simulation::updateEntities() {
  if (world_)
    for (auto entity : world_->entities()) {
      if (entity)
        entity->update();
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

  connect(loopTimer_, SIGNAL(timeout()), simulationWidget_, SLOT(update()));

  connectButtons();

  connectSimulationStarted();
  connectSimulationPaused();
  connectSimulationStopped();
}

void Simulation::generateWorld() {
  // TODO get it from input, if empty generate one
  int time = QTime::currentTime().msecsSinceStartOfDay();
  qsrand(time);

  QDateTime dateTimeNow = QDateTime::currentDateTime();

  int population = inputWidget_->getPopulation();
  int infectionRange = inputWidget_->getInfectionRange();
  int infectionRate = inputWidget_->getInfectionRate();
  int deathRate = inputWidget_->getDeathRate();
  int recoverTime = inputWidget_->getTimeRecover();
  int initialInfects = inputWidget_->getInitialInfect();

  logger_ = new ActorsLogger(dateTimeNow.toString(Qt::ISODate), dateTimeNow,
                             time, population, infectionRange, infectionRate,
                             deathRate, recoverTime, initialInfects);

  world_ = new World(*this, population, infectionRange, infectionRate,
                     deathRate, recoverTime, initialInfects);
}

void Simulation::generateTimer() {
  timer_ = new Timer(this, inputWidget_);
  connect(this, SIGNAL(simulationStarted()), timer_, SLOT(setVisibleClock()));
  connect(this, SIGNAL(simulationPaused()), timer_, SLOT(stop_timer()));
  connect(this, SIGNAL(simulationStopped()), timer_, SLOT(setInvisibleClock()));
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
}

void Simulation::connectSimulationStopped() {
  connect(this, SIGNAL(simulationStopped()), inputWidget_,
          SLOT(enableStartButton()));
  connect(this, SIGNAL(simulationStopped()), inputWidget_,
          SLOT(disablePauseButton()));
  connect(this, SIGNAL(simulationStopped()), inputWidget_,
          SLOT(disableStopButton()));
}

void Simulation::connectSimulationPaused() {
  connect(this, SIGNAL(simulationPaused()), inputWidget_,
          SLOT(simulationPaused()));
  connect(this, SIGNAL(simulationPaused()), inputWidget_,
          SLOT(disableStartButton()));
  connect(this, SIGNAL(simulationPaused()), inputWidget_,
          SLOT(enableStopButton()));
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
  loopTimer_->stop();
  emit simulationStopped();
  durationTimer_->invalidate();
  // method called here because I need every slot to be called before show the
  if (containerWidget_->SaveSimulationAlert()) {
    QString fileUrl = QFileDialog::getSaveFileName(
        containerWidget_, "Scegli il nome della simulazione",
        logger_->getName(), ".json");
    if (!fileUrl.isEmpty())
      logger_->save(fileUrl);
  }

  simulationWidget_->setInvisibleSlot();

  delete world_;
  delete logger_;
}

QElapsedTimer *Simulation::durationTimer() const { return durationTimer_; }