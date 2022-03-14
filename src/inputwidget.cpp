#include "inputwidget.h"

InputWidget::InputWidget(QWidget* parents): QWidget(parents) {
      //variables declaration and inizialization
        //layout
        QVBoxLayout *layout= new QVBoxLayout(this);
        //label
        l_population=new QLabel(this);
        l_infection=new QLabel(this);
        ltime=new QLabel(this);
        l_infection_rt=new QLabel(this);
        l_death=new QLabel(this);
        //input field
        input_pop=new QLineEdit(this);
        input_inf=new QLineEdit(this);
        input_inf_rt=new QSpinBox(this);
        input_dth=new QSpinBox(this);
        //radio menu
        radio_1=new QRadioButton("30s",this);
        radio_2=new QRadioButton("1m",this);
        radio_3=new QRadioButton("3m",this);
        radio_4=new QRadioButton("fino a compleatamento",this);
      //label text
        l_population->setText("Grandezza della Popolazione");
        l_infection->setText("Raggio del Contagio");
        l_infection_rt->setText("Percentuale infezione");
        l_death->setText("percentuale morte");
        ltime->setText("Tempo della Simulazuione");
      //SpinBox max min setting
        input_inf_rt->setMaximum(100);
        input_inf_rt->setMinimum(0);
        input_dth->setMaximum(100);
        input_dth->setMinimum(0);
      //adding widget to layout
        layout->addWidget(l_population);
        layout->addWidget(input_pop);
        layout->addWidget(l_infection);
        layout->addWidget(input_inf);
        layout->addWidget(l_infection_rt);
        layout->addWidget(input_inf_rt);
        layout->addWidget(l_death);
        layout->addWidget(input_dth);
        layout->addWidget(ltime);
        layout->addWidget(radio_1);
        layout->addWidget(radio_2);
        layout->addWidget(radio_3);
        layout->addWidget(radio_4);

        this->setLayout(layout);
}
