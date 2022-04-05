#include "Controllers/Simulation.h"
#include "Views/MainWindow.h"
#include "Views/SimulationView.h"
#include <QApplication>

int main(int argc, char **argv) {
  QApplication app(argc, argv);

  Simulation *s = &Simulation::instance();

  SimulationView *sv = new SimulationView(s);

  s->setView(sv);

  sv->show();

  app.exec();
}
