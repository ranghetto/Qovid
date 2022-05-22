#include "ScatterChart.h"

ScatterChart::ScatterChart(const ActorsLogger &logger) : LoggerChart(logger) {

  QtCharts::QScatterSeries *series0 = new QScatterSeries();
  series0->setName("Contagio");
  series0->setBrush(QColor(LoggerChart::StatusColor::INFECTED));
  series0->setMarkerShape(QScatterSeries::MarkerShapeCircle);
  series0->setMarkerSize(10);

  for (auto i : logger.infections())
    series0->append(i->position().toPointF());

  addSeries(series0);
  setTitle("Posizione");
  createDefaultAxes();
}