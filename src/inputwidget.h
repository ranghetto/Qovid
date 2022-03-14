#ifndef INPUTWIDGET_H
#define INPUTWIDGET_H
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QSpinBox>


class InputWidget: public QWidget
{
    Q_OBJECT
    protected:
        QLabel *l_population, *l_infection, *l_infection_rt, *l_death, *ltime;
        QLineEdit *input_pop, *input_inf;
        QSpinBox *input_inf_rt, *input_dth;
        QRadioButton *radio_1, *radio_2, *radio_3, *radio_4;
    public:
        InputWidget(QWidget* parents=nullptr);
};

#endif // INPUTWIDGET_H
