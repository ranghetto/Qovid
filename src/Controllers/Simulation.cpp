#include "Simulation.h"

Simulation::Simulation(QObject *parent)
    : QObject(parent), world_(nullptr), loopTimer_(new QTimer(this)),
      deltaTimer_(new QElapsedTimer()), isRunning_(false) {
        connect(loopTimer_, SIGNAL(timeout()), this, SLOT(update()));
      }

//slot & signal

//handle signal from "start simulation" button
void Simulation::handleStartSimulation(){
    generateWorld();
    isRunning_=true;
    
    // ->start(0) is a timer configurations to enter in the event loop of Qt.
    // Every time `timeout()` signal is sent, the connecter slots'll be executed
    // in the main loop of Qt, without inferferring with normal operations.
    loopTimer_->start(0);

    // Timer to calculate `deltaTime`
    deltaTimer_->start();
    lastTime_ = deltaTimer_->elapsed();

    view_ = new SimulationView(this);
    this->setView(view_);
    container_widget_->showSimulation(view_);
}

void Simulation::update() {
  if (isRunning_) {
    qint64 current = deltaTimer_->elapsed();
    qint64 elapsed = current - lastTime_;

    // input hanlder should be placed above if exists
    update(elapsed);

    lastTime_ = current;
  }
}

void Simulation::update(qint64 deltaTime) {
  for (auto entity : world_->entities()) {
    if (entity)
      entity->update(deltaTime);
  }
}

//setter & getter

void Simulation::render(QPainter &painter) {
  for (auto entity : world_->entities()) {
    if (entity)
      entity->render(painter);
  }
}

//create mainwindow and set/get pointers
void Simulation::setMainWindow() {
    main_window_=new MainWindow();
    main_window_->setSimulation(this);
    container_widget_=main_window_->getContainer();
    container_widget_->setSimulation(this);
    input_widget_=container_widget_->getInputWidget();
    input_widget_->setSimulation(this);
    main_window_->show();
}

void Simulation::setView(SimulationView *view) {
  view->setController(this);
  view_ = view;
  // TODO implement
  // connect(viewButton, SIGNAL(clicked()), this, SLOT(takeInput()));
}


void Simulation::generateWorld() { 
  int population=input_widget_->getPopulation();
  world_ = new World(population);
}

World *Simulation::world() const { return world_; }

Simulation &Simulation::instance() {
  static Simulation *simulation = new Simulation(nullptr);
  return *simulation;
}
