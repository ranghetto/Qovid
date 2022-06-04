#include "ChartsWidget.h"

ChartsWidget::ChartsWidget(AreaChart &areaChart, PieChart &pieChart,
                           ScatterChart &scatterChart, BarChart &barChart, QWidget *parent)
    : QWidget(parent), layout(new QGridLayout(this)) {
  resize(500, 500);

  areaChartView = new QtCharts::QChartView(&areaChart);
  areaChartView->setRenderHints(QPainter::Antialiasing);

  pieChartView = new QtCharts::QChartView(&pieChart);
  pieChartView->setRenderHints(QPainter::Antialiasing);

  scatterChartView = new QtCharts::QChartView(&scatterChart);
  scatterChartView->setRenderHints(QPainter::Antialiasing);

  barChartView = new QtCharts::QChartView(&barChart);
  barChartView->setRenderHints(QPainter::Antialiasing);

  layout->addWidget(areaChartView, 0, 0);
  layout->addWidget(pieChartView, 0, 1);
  layout->addWidget(scatterChartView, 1, 0);
  layout->addWidget(barChartView, 1, 1);
}