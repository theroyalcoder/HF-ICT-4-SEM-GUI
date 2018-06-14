#include "gui.h"
#include <QDebug>

gui::gui(QWidget *parent)
{
    qDebug() << "GUI konstruktor" << endl;
}

void gui::paintEvent(QPaintEvent *event)
{
    qDebug() << "paintEvent started" << endl;

}
