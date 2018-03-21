#include "mainwindow.h"
#include "mywidget.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MyWidget mw;
    mw.show();

    return a.exec();
}
