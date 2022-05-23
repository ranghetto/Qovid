#include "GraphHandler.h"

GraphHandler::GraphHandler(QObject *parent): QObject(parent), container_(nullptr) {}

void GraphHandler::setContainerWidgets(ContainerWidget* c){
    container_=c;
    simulation_=container_->getOldSimulation();
    simulation_->getHandler(this);
    directory_=new QDir(QDir::currentPath());
    PopulateOldSimulation(getCurrentDirectory());
}

QDir* GraphHandler::getCurrentDirectory(){
    return directory_;
}

void GraphHandler::PopulateOldSimulation(QDir *directory){
    QStringList file_ = directory_->entryList(QStringList() << "*.json", QDir::Files);
    int stack_=file_.length();
    for (int i=0; i<stack_; i++) {
        simulation_->NewWidgetItemAdder(file_.at(i));
    }
}

void GraphHandler::showGraph(QListWidgetItem* sim){
    QFile file(directory_->filePath(sim->text())); 
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
    }
    QByteArray saveData = file.readAll();
    QJsonDocument loadDoc=QJsonDocument::fromJson(saveData);
    ActorsLogger logger_(loadDoc.object());
    PieChart *ch1 = new PieChart(logger_);
    AreaChart *ch2 = new AreaChart(logger_);
    ScatterChart *ch3 = new ScatterChart(logger_);
    ChartsWidget *cw = new ChartsWidget(*ch2, *ch1, *ch3);
    cw->show();
}


