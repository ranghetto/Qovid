#ifndef OLDSIMULATION_H
#define OLDSIMULATION_H

#include <QListWidgetItem>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>

class OldSimulation: public QWidget{
    public:
    void f();
    OldSimulation(QWidget *parent = nullptr);
    private:
    QLabel *label, *label2;
    QListWidget *list_;
};

#endif