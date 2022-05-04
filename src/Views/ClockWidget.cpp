#include "ClockWidget.h"
#include "../Controllers/Simulation.h"

ClockWidget::ClockWidget(QWidget *parent): QWidget(parent) {
    
    label_=new QLabel(this);
    QHBoxLayout *layout=new QHBoxLayout(this);
    label_->setText(QTime(0, 0).toString("mm:ss"));
    //set font
    QFont font = label_->font();
    font.setPointSize(40);
    label_->setFont(font);
    label_->setAlignment(Qt::AlignCenter);
    layout->addWidget(label_);
    this->setLayout(layout);
    this->setInvisibleClock();

    connect(&timer_, SIGNAL(timeout()), this, SLOT(updatetime()));
    connect(this, SIGNAL(start_timer()), this, SLOT(start()));   
}

void ClockWidget::setSimulation(Simulation* controller){ controller_=controller; }

void ClockWidget::updatetime(){ 
    label_->setText(QTime(0, 0).addMSecs(start_time_.elapsed()).toString("mm:ss"));
}

void ClockWidget::start(){
      label_->setText(QTime(0, 0).toString("mm:ss"));
      start_time_.restart();
      timer_.start(1000);
}    

void ClockWidget::setVisibleClock() { 
    setVisible(true);
    emit start_timer();
}

void ClockWidget::setInvisibleClock() { 
    setVisible(false);
}