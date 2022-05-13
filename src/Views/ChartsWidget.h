#ifndef CHARTS_WIDGET_H
#define CHARTS_WIDGET_H

#include "Charts/AreaChart.h"
#include <QGridLayout>
#include <QWidget>
#include <QtCharts>

class ChartsWidget : public QWidget {
public:
  ChartsWidget(AreaChart &areaChart);

private:
  QGridLayout *layout;
  QtCharts::QChartView *areaChartView;
  // Uncomment when adding new charts
  // QtCharts::QChartView *heatmapChartView;
  // QtCharts::QChartView *pieChartView;
  // QtCharts::QChartView *otherChartView;
  // QtCharts::QChartView *other1ChartView;
};

#endif // CHARTS_WIDGET_H