#include "ClockWidget.h"
#include "../Controllers/Timer.h"

ClockWidget::ClockWidget(QWidget *parent): QWidget(parent){
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
    setVisible(false);
}

//methods
void ClockWidget::setController(Timer *controller){controller_=controller;}

void ClockWidget::write(QString s){label_->setText(s);}

void ClockWidget::ShowClock(){ setVisible(true); }

void ClockWidget::HideClock(){ setVisible(false); }


