#include "ChartsWidget.h"

ChartsWidget::ChartsWidget(AreaChart &areaChart, PieChart &pieChart)
    : layout(new QGridLayout(this)) {
  resize(500, 500);

  areaChartView = new QtCharts::QChartView(&areaChart);
  areaChartView->setRenderHints(QPainter::Antialiasing);

  pieChartView = new QtCharts::QChartView(&pieChart);
  pieChartView->setRenderHints(QPainter::Antialiasing);

  layout->addWidget(areaChartView, 0, 0);
  layout->addWidget(pieChartView, 0, 1);

  show();
}