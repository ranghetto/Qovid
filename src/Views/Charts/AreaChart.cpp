#include "AreaChart.h"

AreaChart::AreaChart(const ActorsLogger &logger) : LoggerChart(logger) {
  QtCharts::QLineSeries *lowerBound = new QtCharts::QLineSeries();
  QtCharts::QLineSeries *infected = new QtCharts::QLineSeries();
  QtCharts::QLineSeries *healthy = new QtCharts::QLineSeries();
  QtCharts::QLineSeries *recovered = new QtCharts::QLineSeries();
  QtCharts::QLineSeries *dead = new QtCharts::QLineSeries();

  for (auto moment : logger.moments()) {
    *lowerBound << QPointF(moment->time(), 0);
    *infected << QPointF(moment->time(), moment->infected());
    *healthy << QPointF(moment->time(), moment->infected() + moment->healthy());
    *recovered << QPointF(moment->time(), moment->infected() +
                                              moment->healthy() +
                                              moment->recovered());
    *dead << QPointF(moment->time(), moment->infected() + moment->healthy() +
                                         moment->recovered() + moment->dead());
  }

  QtCharts::QAreaSeries *series0 = 
      new QtCharts::QAreaSeries(infected, healthy);    
  series0->setName("Healthy");
  series0->setBrush(QColor(LoggerChart::StatusColor::HEALTHY));
  QtCharts::QAreaSeries *series1 =
      new QtCharts::QAreaSeries(lowerBound, infected);
  series1->setName("Infected");
  series1->setBrush(QColor(LoggerChart::StatusColor::INFECTED));
  QtCharts::QAreaSeries *series2 =
      new QtCharts::QAreaSeries(healthy, recovered);
  series2->setName("Recovered");
  series2->setBrush(QColor(LoggerChart::StatusColor::RECOVERED));
  QtCharts::QAreaSeries *series3 = new QtCharts::QAreaSeries(recovered, dead);
  series3->setName("Dead");
  series3->setBrush(QColor(LoggerChart::StatusColor::DEAD));

  addSeries(series0);
  addSeries(series1);
  addSeries(series2);
  addSeries(series3);
  setTitle("Andamento Epidemologico");
  createDefaultAxes();
  axes(Qt::Horizontal)
      .first()
      ->setRange(logger.moments().first()->time(),
                 logger.moments().last()->time());
  axes(Qt::Vertical).first()->setRange(0, logger.totalPopulation());
}