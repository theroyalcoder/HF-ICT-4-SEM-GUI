#include "mainwindow.h"
#include "mywidget.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    MyWidget mw;
    mw.show();


    return a.exec();
}
