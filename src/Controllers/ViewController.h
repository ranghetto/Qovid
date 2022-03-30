#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H
#include <QObject>
#include "../Views/MainWindow.h"

class ViewController: public QObject
{
    Q_OBJECT
    public:
        ViewController(QObject *parent = nullptr);
        virtual ~ViewController(){};
        void show();
    private:
        MainWindow *main_window_;
};

#endif // VIEWCONTROLLER_H
