#ifndef CONTAINERWIDGET_H
#define CONTAINERWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include "inputwidget.h"

class ContainerWidget: public QWidget
{
    Q_OBJECT
    private:
        InputWidget *widget1;
    public:
        ContainerWidget(QWidget *parents=nullptr);
        ~ContainerWidget()=default;
};

#endif // CONTAINERWIDGET_H
