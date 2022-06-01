#include "Simulation.h"
#include <QString>

Simulation::Simulation(QObject *parent)
    : QObject(parent), saveSimulation_(nullptr), world_(nullptr),
      timer_(nullptr), loopTimer_(new QTimer(this)),
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
    emit lineStop();
    loopTimer_->stop();
    pausedTimer_->start();
  } else {
    emit lineStart();
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
  if (world_ && isRunning())
    for (auto entity : world_->entities()) {
      if (entity)
        entity->update();
    }
}

void Simulation::render(QPainter &painter) {
  if (world_ && isRunning())
    for (auto entity : world_->entities()) {
      if (entity)
        entity->render(painter);
    }
}

void Simulation::setContainerWidgets(ContainerWidget *container) {
  containerWidget_ = container;

  containerWidget_->getInputWidget()->setController(this);
  containerWidget_->getSimulationWidget()->setController(this);
  containerWidget_->setController(this);

  connect(loopTimer_, SIGNAL(timeout()),
          containerWidget_->getSimulationWidget(), SLOT(update()));

  connectButtons();

  connectSimulationStarted();
  connectSimulationPaused();
  connectSimulationStopped();
}

#include "../Views/Charts/LineChart.h"
#include <QChartView>

void Simulation::generateWorld() {
  // TODO get it from input, if empty generate one
  int time = QTime::currentTime().msecsSinceStartOfDay();
  qsrand(time);

  QDateTime dateTimeNow = QDateTime::currentDateTime();

  InputWidget *i = containerWidget_->getInputWidget();

  int population = i->getPopulation();
  int infectionRange = i->getInfectionRange();
  int infectionRate = i->getInfectionRate();
  int deathRate = i->getDeathRate();
  int recoverTime = i->getTimeRecover();
  int initialInfects = i->getInitialInfect();

  logger_ = new ActorsLogger(dateTimeNow.toString(Qt::ISODate), dateTimeNow,
                             time, population, infectionRange, infectionRate,
                             deathRate, recoverTime, initialInfects);

  world_ = new World(*this, population, infectionRange, infectionRate,
                     deathRate, recoverTime, initialInfects);

  LineChart *c = new LineChart(*this);
  c->setAnimationOptions(QtCharts::QChart::SeriesAnimations);
  QtCharts::QChartView *v = new QtCharts::QChartView(c);
  v->setRenderHint(QPainter::Antialiasing);
  v->show();
}

void Simulation::generateTimer() {
  timer_ = new Timer(this, containerWidget_->getInputWidget());
  connect(this, SIGNAL(simulationStarted()), timer_, SLOT(setVisibleClock()));
  connect(this, SIGNAL(simulationPaused()), timer_, SLOT(stop_timer()));
  connect(this, SIGNAL(simulationStopped()), timer_,
          SLOT(setInvisibleandDestroyClock()));
}

void Simulation::connectSimulationStarted() {
  connect(this, SIGNAL(simulationStarted()), containerWidget_->getInputWidget(),
          SLOT(disableStartButton()));
  connect(this, SIGNAL(simulationStarted()), containerWidget_->getInputWidget(),
          SLOT(enablePauseButton()));
  connect(this, SIGNAL(simulationStarted()), containerWidget_->getInputWidget(),
          SLOT(enableStopButton()));
  connect(this, SIGNAL(simulationStarted()),
          containerWidget_->getSimulationWidget(), SLOT(setVisibleSlot()));
}

void Simulation::connectSimulationStopped() {
  connect(this, SIGNAL(simulationStopped()), containerWidget_->getInputWidget(),
          SLOT(enableStartButton()));
  connect(this, SIGNAL(simulationStopped()), containerWidget_->getInputWidget(),
          SLOT(disablePauseButton()));
  connect(this, SIGNAL(simulationStopped()), containerWidget_->getInputWidget(),
          SLOT(disableStopButton()));
}

void Simulation::connectSimulationPaused() {
  connect(this, SIGNAL(simulationPaused()), containerWidget_->getInputWidget(),
          SLOT(simulationPaused()));
  connect(this, SIGNAL(simulationPaused()), containerWidget_->getInputWidget(),
          SLOT(disableStartButton()));
  connect(this, SIGNAL(simulationPaused()), containerWidget_->getInputWidget(),
          SLOT(enableStopButton()));
}

void Simulation::connectButtons() {
  connect(containerWidget_->getInputWidget()->startSimButton(),
          SIGNAL(clicked()), this, SLOT(startSimulation()));
  connect(containerWidget_->getInputWidget()->pauseSimButton(),
          SIGNAL(clicked()), this, SLOT(toggleSimulation()));
  connect(containerWidget_->getInputWidget()->stopSimButton(),
          SIGNAL(clicked()), this, SLOT(stopSimulation()));
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

  containerWidget_->getSimulationWidget()->setInvisibleSlot();

  delete world_;
  delete logger_;
}

QElapsedTimer *Simulation::durationTimer() const { return durationTimer_; }

Simulation::~Simulation() {
  delete containerWidget_;
  delete world_;
  delete timer_;
  delete loopTimer_;
  delete deltaTimer_;
  delete pausedTimer_;
  delete durationTimer_;
}
