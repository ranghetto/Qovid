#ifndef SCATTER_CHART_H
#define SCATTER_CHART_H

#include "../../Loggers/ActorsLogger.h"
#include "LoggerChart.h"

class ScatterChart : public LoggerChart {
public:
  ScatterChart(const ActorsLogger &logger);
  ~ScatterChart() {}
};

#endif // SCATTER_CHART_H