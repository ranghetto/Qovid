#ifndef LINE_CHART_H
#define LINE_CHART_H

#include <QChart>
#include <QGraphicsItem>
#include <QSplineSeries>
#include <QTimer>
#include <QValueAxis>

class Simulation;

class LineChart : public QtCharts::QChart {
  Q_OBJECT
public:
  LineChart(const Simulation &simulation, QGraphicsItem *parent = nullptr);
public slots:
  void updateChart();

private:
  const Simulation &sim_;
  QTimer timer_;
  QtCharts::QSplineSeries *series_;
  QStringList titles_;
  QtCharts::QValueAxis *axis_;
  qreal step_;
  qreal x_;
};

#endif // LINE_CHART_H