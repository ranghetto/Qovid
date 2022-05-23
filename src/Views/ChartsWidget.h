#ifndef CHARTS_WIDGET_H
#define CHARTS_WIDGET_H

#include "Charts/AreaChart.h"
#include "Charts/PieChart.h"
#include "Charts/ScatterChart.h"
#include <QGridLayout>
#include <QWidget>
#include <QtCharts>

class ChartsWidget : public QWidget {
public:
  ChartsWidget(AreaChart &areaChart, PieChart &pieChart,
               ScatterChart &scatterChart, QWidget *parent = nullptr);

private:
  QGridLayout *layout;
  QtCharts::QChartView *areaChartView;
  QtCharts::QChartView *pieChartView;
  QtCharts::QChartView *scatterChartView;
  // Uncomment when adding new charts
  // QtCharts::QChartView *otherChartView;
  // QtCharts::QChartView *other1ChartView;
};

#endif // CHARTS_WIDGET_H