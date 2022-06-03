#include "LineChart.h"
#include "../../Controllers/Simulation.h"

LineChart::LineChart(const Simulation &simulation, QGraphicsItem *parent)
    : QtCharts::QChart(parent), sim_(simulation),
      series_(new QtCharts::QSplineSeries(this)),
      axis_(new QtCharts::QValueAxis()), step_(5), x_(0) {
  connect(&timer_, SIGNAL(timeout()), this, SLOT(updateChart()));
  connect(&sim_, SIGNAL(lineStop()), &timer_, SLOT(stop()));
  connect(&sim_, SIGNAL(lineStart()), &timer_, SLOT(start()));
  connect(&sim_, SIGNAL(simulationStopped()), &timer_, SLOT(stop()));
  timer_.setInterval(1000);

  QPen red(Qt::red);
  red.setWidth(3);
  series_->setPen(red);

  addSeries(series_);
  createDefaultAxes();
  setAxisX(axis_, series_);
  axis_->setTickCount(5);
  axisX()->setRange(0, 10);
  axisY()->setRange(0, sim_.world()->actorsCount());

  timer_.start();
}

LineChart::~LineChart() {
  delete series_;
  delete axis_;
}

void LineChart::updateChart() {
  x_++;
  series_->append(x_, sim_.world()->infectedCount());
  axisX()->setRange(0, x_ + step_);
}