#include "ChartsWidget.h"

ChartsWidget::ChartsWidget(AreaChart &areaChart)
    : layout(new QGridLayout(this)) {
  resize(500, 500);

  areaChartView = new QtCharts::QChartView(&areaChart);
  areaChartView->setRenderHints(QPainter::Antialiasing);

  layout->addWidget(areaChartView, 0, 0);

  show();
}