#include "Timer.h"
#include "../Controllers/Simulation.h"

Timer::Timer(Simulation *simulation, InputWidget* widget, QObject *parent)
: simulation_(simulation), widget_(widget), clock_(nullptr){

    sim_duration_=0;
    clock_=widget_->getClock();
    clock_->setController(this);
    //connect
    connect(this, SIGNAL(start()), this, SLOT(start_timer())); 
    connect(this, SIGNAL(resume()), this, SLOT(updatetime()));
    connect(&update_, SIGNAL(timeout()), this, SLOT(updatetime()));
}

//methods

QString Timer::createQString(int minutes, int seconds) const {
    QString s;
    if(seconds>=10)
        {s=("0"+QString::number(minutes)+" : "+QString::number(seconds));}
    else
        {s=("0"+QString::number(minutes)+" : 0"+QString::number(seconds));}
    return s;
}

//slot

void Timer::updatetime(){ 
    int minutes, seconds;
    sim_duration_+=1000;
    minutes=(sim_duration_/60000)%60;
    seconds=(sim_duration_/1000)%60;
    clock_->write(createQString(minutes, seconds));
}

void Timer::start_timer(){
    isRunning_=true;
    updatetime();
    update_.start(1000);  
}    

void Timer::stop_timer(){
    if(isRunning_)
    {   
        isRunning_=false;
        update_.stop();
    }
    else
    {
        isRunning_=true;
        update_.start(1000);
        emit resume();
    }
}


void Timer::setInvisibleClock(){
    sim_duration_=0;
    update_.stop();
    clock_->HideClock();
}

void Timer::setVisibleClock() { 
    emit start();
    clock_->ShowClock();
}
