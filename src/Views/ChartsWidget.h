#ifndef CHARTS_WIDGET_H
#define CHARTS_WIDGET_H

#include "Charts/AreaChart.h"
#include "Charts/PieChart.h"
#include "Charts/ScatterChart.h"
#include "Charts/BarChart.h"
#include <QGridLayout>
#include <QWidget>
#include <QtCharts>

class ChartsWidget : public QWidget {
public:
  ChartsWidget(AreaChart &areaChart, PieChart &pieChart,
               ScatterChart &scatterChart, BarChart &barChart, QWidget *parent = nullptr);

private:
  QGridLayout *layout;
  QtCharts::QChartView *areaChartView;
  QtCharts::QChartView *pieChartView;
  QtCharts::QChartView *scatterChartView;
  QtCharts::QChartView *barChartView;
  // Uncomment when adding new charts
  // QtCharts::QChartView *otherChartView;
};

#endif // CHARTS_WIDGET_H