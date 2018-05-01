#include "mainwindow.h"
#include "mainwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("QTG");
    w.show();
    //w.resize(QSize(900, 900));

    return a.exec();
}
