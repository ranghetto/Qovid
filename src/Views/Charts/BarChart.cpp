#include "BarChart.h"

BarChart::BarChart(const ActorsLogger &logger) : LoggerChart(logger) {
    QBarSeries *series=new QBarSeries();
    
    QBarSet *set0 = new QBarSet("Healty");
    set0->setBrush(QColor(LoggerChart::StatusColor::HEALTHY));
    QBarSet *set1 = new QBarSet("Infected");
    set1->setBrush(QColor(LoggerChart::StatusColor::INFECTED));
    QBarSet *set2 = new QBarSet("Recovered");
    set2->setBrush(QColor(LoggerChart::StatusColor::RECOVERED));
    QBarSet *set3 = new QBarSet("Dead");
    set3->setBrush(QColor(LoggerChart::StatusColor::DEAD));

    //column

    int step=logger.moments().size()/4, temp=logger.moments().first()->time();
    QStringList categories;
    QString bar_init=createQString(logger.moments().first()->time());
    categories<<bar_init;
    *set0<<logger.moments().first()->healthy();
    *set1<<logger.moments().first()->infected();
    *set2<<logger.moments().first()->recovered();
    *set3<<logger.moments().first()->dead();

    //If the simulation lasts very little (<4s) graph only shows two column, logger.moments().first()/last();
    //otherwise it shows 5

    if(step!=0){
        for(int i=step; i<logger.moments().size(); i=i+step )
        {
            if(logger.moments().at(i)->time()!=temp)
            {
                qDebug()<<logger.moments().at(i)->time();
                temp=logger.moments().at(i)->time();
                QString bar=createQString(logger.moments().at(i)->time());
                categories<<bar;
                *set0<<logger.moments().at(i)->healthy();
                *set1<<logger.moments().at(i)->infected();
                *set2<<logger.moments().at(i)->recovered();
                *set3<<logger.moments().at(i)->dead();
            }
            if(i+step>=logger.moments().size())
            {
                QString bar=createQString(logger.moments().last()->time());
                categories<<bar;
                *set0<<logger.moments().last()->healthy();
                *set1<<logger.moments().last()->infected();
                *set2<<logger.moments().last()->recovered();
                *set3<<logger.moments().last()->dead();
            }
        }
    }
    else
    {
        QString bar_fin=createQString(logger.moments().last()->time());
        categories<<bar_fin;
        *set0<<logger.moments().last()->healthy();
        *set1<<logger.moments().last()->infected();
        *set2<<logger.moments().last()->recovered();
        *set3<<logger.moments().last()->dead();
    }

    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    addSeries(series);

    setTitle("Grafico a Barre");
    
    //axis

    createDefaultAxes();
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    setAxisX(axisX);
    axes(Qt::Vertical).first()->setRange(0, logger.totalPopulation());
    
}

QString BarChart::createQString(int time)
{
    QString s;
    int minutes=time/60;
    int seconds=time%60;
    if(minutes>=10)
    {
        if(seconds>=10)
        {   s=(QString::number(minutes)+" : "+QString::number(seconds));    }
        else
        {   s=(QString::number(minutes)+" : 0"+QString::number(seconds));    }
    }
    else
    {
        if(seconds>=10)
        {   s=(QString::number(minutes)+"0 : "+QString::number(seconds));    }
        else
        {   s=(QString::number(minutes)+"0 : 0"+QString::number(seconds));    }
    }
    return s;
}

/*QStringList categories;
    QString bar0=createQString(logger.moments().first()->time());
    QString bar1=createQString(logger.moments().at(i+step)->time());
    QString bar2=createQString(logger.moments().at(i+step*2)->time());
    QString bar3=createQString(logger.moments().at(i+step*3)->time());
    QString bar4=createQString(logger.moments().last()->time());
    categories << bar0 << bar1 << bar2 << bar3 << bar4;
    
    *set0<<
            logger.moments().first()->healthy() <<
            logger.moments().at(i+step)->healthy() <<
            logger.moments().at(i+step*2)->healthy() <<
            logger.moments().at(i+step*3)->healthy() <<
            logger.moments().last()->healthy();
    *set1<<
            logger.moments().first()->infected() <<
            logger.moments().at(i+step)->infected() <<
            logger.moments().at(i+step*2)->infected() <<
            logger.moments().at(i+step*3)->infected() <<
            logger.moments().last()->infected();
    *set2<<
            logger.moments().first()->recovered() <<
            logger.moments().at(i+step)->recovered() <<
            logger.moments().at(i+step*2)->recovered() <<
            logger.moments().at(i+step*3)->recovered() <<
            logger.moments().last()->recovered();
    *set3<<
            logger.moments().first()->dead() <<
            logger.moments().at(i+step)->dead() <<
            logger.moments().at(i+step*2)->dead() <<
            logger.moments().at(i+step*3)->dead() <<
            logger.moments().last()->dead();



    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    addSeries(series);*/