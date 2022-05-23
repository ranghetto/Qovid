#ifndef SCATTER_CHART_H
#define SCATTER_CHART_H

#include "../../Loggers/ActorsLogger.h"
#include "LoggerChart.h"

class ScatterChart : public LoggerChart {
public:
  ScatterChart(const ActorsLogger &logger);
};

#endif // SCATTER_CHART_H