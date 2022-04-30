#include "Controllers/Simulation.h"
#include "Views/ContainerWidget.h"
#include "Views/MainWindow.h"
#include <QApplication>

int main(int argc, char **argv) {
  QApplication app(argc, argv);

  MainWindow m;
  ContainerWidget *c = m.getContainerWidget();

  // setContainerWidget() will set InputWidget & SimulationWidget
  Simulation *s = new Simulation();
  s->setContainerWidgets(c);

  m.show();

  app.exec();
}
