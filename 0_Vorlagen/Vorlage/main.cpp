#include "widget.h"
#include <QApplication>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setMinimumSize(500,500);
    w.show();

    return a.exec();

}

