#include "LoggerChart.h"

LoggerChart::LoggerChart(const ActorsLogger &logger, QGraphicsItem *parent)
    : QtCharts::QChart(parent), logger_(logger) {
  setAnimationOptions(QChart::SeriesAnimations);
}

const ActorsLogger &LoggerChart::logger() { return logger_; }

LoggerChart::~LoggerChart() {}