#include "containerwidget.h"

ContainerWidget::ContainerWidget(QWidget *parents)
{
    input_widget=new InputWidget(this);
    QHBoxLayout *layout=new QHBoxLayout(this);
    layout->addWidget(input_widget);
    this->setLayout(layout);
}
