#ifndef AREA_CHART_H
#define AREA_CHART_H

#include "../../Loggers/ActorsLogger.h"
#include "LoggerChart.h"

class AreaChart : public LoggerChart {
public:
  AreaChart(const ActorsLogger &logger);
};

#endif // AREA_CHART_H