#ifndef AREA_CHART_H
#define AREA_CHART_H

#include "../../Loggers/ActorsLogger.h"
#include <QtCharts>

class AreaChart : public QtCharts::QChart {
public:
  AreaChart(const ActorsLogger &logger);
};

#endif // AREA_CHART_H