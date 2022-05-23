#ifndef GRAPHHANDLER_H
#define GRAPHHANDLER_H
#include <QObject>
#include <QListWidgetItem>
#include <QDir>
#include <QDebug>
#include "../Views/ContainerWidget.h"
#include "../Views/OldSimulation.h"

class GraphHandler: public QObject{
    Q_OBJECT
    public:
    GraphHandler(QObject *parent = nullptr);
    void setContainerWidgets(ContainerWidget*);
    QDir* getCurrentDirectory();
    void PopulateOldSimulation(QDir*);
    public slots:
    void showGraph(QListWidgetItem*);
    private:
    ContainerWidget* container_;
    OldSimulation* simulation_;
    QDir *directory_;
};


#endif