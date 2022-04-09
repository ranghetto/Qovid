#include "Controllers/Simulation.h"
#include "Views/SimulationView.h"
#include <QApplication>

int main(int argc, char **argv) {
  QApplication app(argc, argv);

  // Create an instance of Simulation
  // Don't need to be saved anywhere 'cause it's a singleton so it is
  // always available by calling `instance()` method
  Simulation::instance();

  app.exec();
}
