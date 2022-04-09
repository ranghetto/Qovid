#include "Simulation.h"

Simulation::Simulation(QObject *parent)
    : QObject(parent), world_(nullptr), loopTimer_(new QTimer(this)),
      deltaTimer_(new QElapsedTimer) {

  connect(loopTimer_, SIGNAL(timeout()), this, SLOT(update()));
}

// SIGNAL & SLOTS
// handle signal from "start simulation" button
void Simulation::handleStartSimulation() {

  inputWidget_->disableSimulationButton();

  createSimulationWidgetAndAddToContainerLayout();

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

// SETTERS
void Simulation::createSimulationWidgetAndAddToContainerLayout() {
  simulationWidget_ = new SimulationWidget(this, containerWidget_);
  containerWidget_->addSimulationWidget(simulationWidget_);
  // Connect timer to QWidget::SimulationWidget update() method
  connect(loopTimer_, SIGNAL(timeout()), simulationWidget_, SLOT(update()));
}

void Simulation::toggleSimulation() const {
  if (isRunning())
    loopTimer_->stop();
  else
    loopTimer_->start(0);
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

void Simulation::setContainerAndInputWidget(ContainerWidget *container) {
  containerWidget_ = container;
  inputWidget_ = container->getInputWidget();
  inputWidget_->setSimulation(this);
}

void Simulation::generateWorld() {
  int population = inputWidget_->getPopulation();
  world_ = new World(population);
}

Simulation &Simulation::instance() {
  static Simulation *simulation = new Simulation(nullptr);
  return *simulation;
}
