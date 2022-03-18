#include <QApplication>
#include "MainWindow.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    //Main Window...
    MainWindow w;
    w.show();
    app.exec();
}
