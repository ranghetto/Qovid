#include "GraphHandler.h"

GraphHandler::GraphHandler(QObject *parent): QObject(parent), container_(nullptr) {}

void GraphHandler::setContainerWidgets(ContainerWidget* c){
    container_=c;
    setOldSimulation();
}

void GraphHandler::setOldSimulation(){
    simulation_=container_->getOldSimulation();
}

