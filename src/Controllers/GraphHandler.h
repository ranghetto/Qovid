#ifndef GRAPHHANDLER_H
#define GRAPHHANDLER_H
#include <QObject>
#include "../Views/ContainerWidget.h"
#include "../Views/OldSimulation.h"

class GraphHandler: public QObject{
    Q_OBJECT
    public:
    GraphHandler(QObject *parent = nullptr);
    void setContainerWidgets(ContainerWidget*);
    private:
    void setOldSimulation();
    ContainerWidget* container_;
    OldSimulation* simulation_;
};


#endif