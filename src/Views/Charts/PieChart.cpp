#include "PieChart.h"

PieChart::PieChart(const ActorsLogger &logger) : LoggerChart(logger) {
  QPieSeries *series = new QPieSeries();
  series->append("Healthy", logger.moments().last()->healthy());
  series->append("Infected", logger.moments().last()->infected());
  series->append("Recovered", logger.moments().last()->recovered());
  series->append("Dead", logger.moments().last()->dead());

  QPieSlice *slice = series->slices().at(0);
  slice->setExploded();
  slice->setLabelVisible();
  slice->setBrush(QColor(LoggerChart::StatusColor::HEALTHY));

  series->slices().at(1)->setBrush(QColor(LoggerChart::StatusColor::INFECTED));
  series->slices().at(2)->setBrush(QColor(LoggerChart::StatusColor::RECOVERED));
  series->slices().at(3)->setBrush(QColor(LoggerChart::StatusColor::DEAD));

  addSeries(series);
  setTitle("Ultimo Istante di Tempo");
}