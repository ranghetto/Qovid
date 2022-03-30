#include "Controllers/Simulation.h"
#include "Controllers/ViewController.h"
#include "Views/SimulationView.h"
#include <QApplication>

int main(int argc, char **argv) {
  QApplication app(argc, argv);

  ViewController *c=new ViewController();

  //Simulation *s = new Simulation();

  //SimulationView *sv = new SimulationView(s);

  //s->setView(sv);

  //sv->show();
  c->show();
  app.exec();
}
