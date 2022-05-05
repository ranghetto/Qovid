#include "ClockWidget.h"
#include "../Controllers/Simulation.h"

ClockWidget::ClockWidget(QWidget *parent): QWidget(parent), isRunning(false) {
    //pointer inizialization
    label_=new QLabel(this);
    QHBoxLayout *layout=new QHBoxLayout(this);
    //set font
    QFont font = label_->font();
    font.setPointSize(40);
    label_->setFont(font);
    //set aligment
    label_->setAlignment(Qt::AlignCenter);
    //widget visualization
    layout->addWidget(label_);
    setLayout(layout);
    setInvisibleClock();
    //connect
    connect(&update_, SIGNAL(timeout()), this, SLOT(updatetime()));
    connect(&sim_timer_, SIGNAL(timeout()), this, SLOT(fine()));
    connect(this, SIGNAL(resume()), this, SLOT(updatetime())); 
    connect(this, SIGNAL(start()), this, SLOT(start_timer())); 
}

//methods
QString ClockWidget::createQString(){
    int minute=sim_timer_.remainingTime()/60000;
    int seconds=sim_timer_.remainingTime()/1000;
    QString s;
    if(seconds%10 || !seconds)
        {s=("0"+QString::number(minute)+" : 0"+QString::number(seconds));}
    else
        {s=("0"+QString::number(minute)+" : "+QString::number(seconds));}
    return s;
}

//setter
void ClockWidget::setSimulation(Simulation* controller){ controller_=controller; }

//slot
void ClockWidget::fine(){}

void ClockWidget::updatetime(){ 
    label_->setText(createQString());
}

void ClockWidget::start_timer(){
    isRunning=true;
    sim_timer_.setSingleShot(true);
    sim_timer_.start(3000);
    update_.start(10);    
}    

void ClockWidget::stop_timer(){
    if(isRunning)
    {   
        isRunning=false;
        temp=sim_timer_.remainingTime();
        sim_timer_.stop();
        update_.stop();
    }
    else
    {
        isRunning=true;
        update_.start(10);
        sim_timer_.start(temp);
        emit resume();
    }
}

void ClockWidget::setVisibleClock() { 
    emit start();
    setVisible(true);
}

void ClockWidget::setInvisibleClock() { 
    setVisible(false);
}