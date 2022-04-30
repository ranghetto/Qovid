#include "Controllers/Simulation.h"
#include "Views/ContainerWidget.h"
#include "Views/MainWindow.h"
#include <QApplication>

int main(int argc, char **argv) {
  QApplication app(argc, argv);

  MainWindow m;
  ContainerWidget *c = m.getContainerWidget();

  // Create an instance of Simulation
  // Don't need to be saved anywhere 'cause it's a singleton so it is
  // always available by calling `instance()` method

  // setContainerWidget() will set InputWidget & SimulationWidget
  Simulation::instance().setContainerWidgets(c);

  m.show();

  app.exec();
}
