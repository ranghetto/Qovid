#ifndef INPUTWIDGET_H
#define INPUTWIDGET_H
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QSpinBox>
#include <QPushButton>

class InputWidget: public QWidget
{
    Q_OBJECT
    protected:
        QLabel *label_population, *label_infection, *label_infection_rate, *label_death_rate, *label_time;
        QSpinBox *input_population, *input_infection, *input_infection_rate, *input_death_rate;
        QRadioButton *sim_duration_30s, *sim_duration_1m, *sim_duration_3m, *sim_duration_complete;
        QPushButton *start_sim;
    public:
        InputWidget(QWidget* parent=nullptr);
};

#endif // INPUTWIDGET_H
