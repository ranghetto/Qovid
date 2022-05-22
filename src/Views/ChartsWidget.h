#ifndef CHARTS_WIDGET_H
#define CHARTS_WIDGET_H

#include "Charts/AreaChart.h"
#include "Charts/PieChart.h"
#include <QGridLayout>
#include <QWidget>
#include <QtCharts>

class ChartsWidget : public QWidget {
public:
  ChartsWidget(AreaChart &areaChart, PieChart &pieChart);

private:
  QGridLayout *layout;
  QtCharts::QChartView *areaChartView;
  QtCharts::QChartView *pieChartView;
  // Uncomment when adding new charts
  // QtCharts::QChartView *otherChartView;
  // QtCharts::QChartView *otherChartView;
  // QtCharts::QChartView *other1ChartView;
};

#endif // CHARTS_WIDGET_H