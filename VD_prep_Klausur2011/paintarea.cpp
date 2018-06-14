#include "paintarea.h"

#include <QPainter>
#include <QDebug>

PaintArea::PaintArea(QWidget *parent) : QWidget(parent)
{
    qDebug() << "PaintArea Konstruktur";
}

void PaintArea::setNumberOfPoints(int numberOfPoints)
{

}

void PaintArea::paintEvent(QPaintEvent *event)
{
    qDebug() << "PaintEvent";

    QPainter painter(this);

    painter.drawLine(20, 20, 100, 125);
    painter.drawRect(0, 0, width()-1, height()-1);
}

void PaintArea::setResetFlag(bool value)
{

}

double PaintArea::getResult() const
{
    return result;
}
