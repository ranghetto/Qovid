#ifndef GRAPHHANDLER_H
#define GRAPHHANDLER_H
#include "../Loggers/ActorsLogger.h"
#include "../Views/Charts/AreaChart.h"
#include "../Views/Charts/BarChart.h"
#include "../Views/Charts/PieChart.h"
#include "../Views/Charts/ScatterChart.h"
#include "../Views/ChartsWidget.h"
#include "../Views/ContainerWidget.h"
#include "../Views/OldSimulation.h"
#include <QDir>
#include <QListWidgetItem>
#include <QObject>

class GraphHandler : public QObject {
  Q_OBJECT
public:
  GraphHandler(QObject *parent = nullptr);
  void setContainerWidgets(ContainerWidget *);
  QDir *getCurrentDirectory();
  void PopulateOldSimulation(QDir *);
public slots:
  void showGraph(QListWidgetItem *);

private:
  ContainerWidget *container_;
  OldSimulation *simulation_;
  QDir *directory_;
};

#endif