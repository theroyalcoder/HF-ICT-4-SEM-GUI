#include "widget.h"
#include "thread.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    Datacontainer *c = new Datacontainer;

    Writer *wr1 = new Writer(c);
    Writer *wr2 = new Writer(c);

    Reader *re1 = new Reader(c);
    Reader *re2 = new Reader(c);

    wr1->start();
    wr2->start();
    re1->start();
    re2->start();

    return a.exec();
}
