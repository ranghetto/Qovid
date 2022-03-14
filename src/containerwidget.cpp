#include "containerwidget.h"

ContainerWidget::ContainerWidget(QWidget *parents)
{
    widget1=new InputWidget(this);
    QHBoxLayout *layout=new QHBoxLayout(this);
    layout->addWidget(widget1);
    this->setLayout(layout);
}
