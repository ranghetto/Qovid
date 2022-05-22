#ifndef PIE_CHART_H
#define PIE_CHART_H

#include "../../Loggers/ActorsLogger.h"
#include "LoggerChart.h"

class PieChart : public LoggerChart {
public:
  PieChart(const ActorsLogger &logger);
};

#endif // PIE_CHART_H