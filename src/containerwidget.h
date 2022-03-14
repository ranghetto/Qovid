#ifndef CONTAINERWIDGET_H
#define CONTAINERWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include "inputwidget.h"

class ContainerWidget: public QWidget
{
    Q_OBJECT
    private:
        InputWidget *input_widget;
    public:
        ContainerWidget(QWidget *parent=nullptr);
        ~ContainerWidget()=default;
};

#endif // CONTAINERWIDGET_H
