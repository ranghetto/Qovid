#include "Timer.h"
#include "../Controllers/Simulation.h"

Timer::Timer(Simulation *simulation, InputWidget* widget, QObject *parent)
: simulation_(simulation), widget_(widget), clock_(nullptr){

    sim_duration_=0;
    clock_=widget_->getClock();
    clock_->setController(this);
    //connect
    connect(&update_, SIGNAL(timeout()), this, SLOT(updatetime()));
    connect(&sim_timer_, SIGNAL(timeout()), this, SLOT(pressButton()));
    connect(this, SIGNAL(start()), this, SLOT(start_timer())); 
    connect(this, SIGNAL(resume()), this, SLOT(updatetime()));
}

//methods

QString Timer::createQString(int minutes, int seconds){
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
    if(!isUntillEnd_)
    {
        minutes=(sim_timer_.remainingTime()/60000)%60;
        seconds=(sim_timer_.remainingTime()/1000)%60;    
    }
    else
    {
        sim_duration_+=1000;
        minutes=(sim_duration_/60000)%60;
        seconds=(sim_duration_/1000)%60;
    }
    clock_->write(createQString(minutes, seconds));
}

void Timer::start_timer(){
    isRunning_=true;
    if(sim_duration_)
    {
        isUntillEnd_=false;
        sim_timer_.setSingleShot(true);
        //sim_timer_.start(sim_duration_);
        sim_timer_.start(5000);
        update_.start(10);
    }
    else
    {
        isUntillEnd_=true;
        update_.start(1000);
    }   
}    

void Timer::stop_timer(){
    if(isRunning_)
    {   
        isRunning_=false;
        update_.stop();
        if(!isUntillEnd_){
        temp_=sim_timer_.remainingTime();
        sim_timer_.stop();
        }
    }
    else
    {
        isRunning_=true;
        update_.start(1000);
        if(!isUntillEnd_){
            sim_timer_.start(temp_);
            update_.start(10);
        }
        else
        {update_.start(1000);}
        emit resume();
    }
}

void Timer::endOfSimulation(){
    clock_->HideClock();
    sim_timer_.stop();
    update_.stop();
}

void Timer::pressButton(){
    emit widget_->stopSimButton()->clicked();
}

void Timer::setVisibleClock() { 
    sim_duration_=widget_->getSimulationTime();
    emit start();
    clock_->ShowClock();
}
