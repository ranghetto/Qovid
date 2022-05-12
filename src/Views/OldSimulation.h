#ifndef OLDSIMULATION_H
#define OLDSIMULATION_H

#include <QPushButton>
#include <QHBoxLayout>
#include <QWidget>
#include <QLabel>

class OldSimulation: public QWidget{
    public:
    OldSimulation(QWidget *parent = nullptr);
    private:
    QLabel *label;
};

#endif