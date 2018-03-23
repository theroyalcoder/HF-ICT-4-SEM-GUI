#include "kunst.h"

#include <QDebug>
#include <QPainter>

Kunst::Kunst(QWidget *parent)
    : QWidget (parent)
{
}

void Kunst::kunstEvent(QPaintEvent *event)
{
    qDebug() << "qPainter";
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 5));
    painter.drawLine(20, 20, 100, 125);
    painter.drawRect(0, 0, width()-1, height()-1);
    painter.drawPoint(10, 10);

}
