#include "widget.h"
#include "kunst.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget *w = new Widget;
    w->show();


    Kunst *k = new Kunst;
    k->show();

    return a.exec();
}
