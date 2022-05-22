#ifndef OLDSIMULATION_H
#define OLDSIMULATION_H

#include <QListWidgetItem>
#include <QDir>
#include <QPushButton>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>

class GraphHandler;

class OldSimulation: public QWidget{
    Q_OBJECT
    public:
    OldSimulation(QWidget *parent = nullptr);
    void NewWidgetItemAdder(const QString);
    void getHandler(GraphHandler*);
    public slots:
    void Refresh();
    private:
    QListWidget *list_;
    GraphHandler *controller_;
    QPushButton *refresh_;
};

#endif