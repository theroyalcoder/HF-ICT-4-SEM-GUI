#include "gui.h"
#include "paintarea.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Gui g;
    g.show();

    return a.exec();
}
