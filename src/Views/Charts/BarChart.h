#ifndef BARCHART_H
#define BARCHART_H

#include "../../Loggers/ActorsLogger.h"
#include "LoggerChart.h"
#include <QDebug>

class BarChart : public LoggerChart {
public:
  BarChart(const ActorsLogger&);
  QString createQString(int time);
};

#endif // BARCHART_H