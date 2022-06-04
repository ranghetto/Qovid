#ifndef LOGGER_CHART_H
#define LOGGER_CHART_H

#include "../../Loggers/ActorsLogger.h"
#include <QtCharts>

class LoggerChart : public QtCharts::QChart {
private:
  const ActorsLogger &logger_;

public:
  LoggerChart(const ActorsLogger &logger, QGraphicsItem *parent = nullptr);

  enum StatusColor {
    DEAD = qRgb(191, 191, 191),
    RECOVERED = qRgb(89, 150, 211),
    HEALTHY = qRgb(129, 208, 102),
    INFECTED = qRgb(230, 57, 70)
  };
  const ActorsLogger &logger();
  virtual ~LoggerChart() = 0;
};

#endif // LOGGER_CHART_H