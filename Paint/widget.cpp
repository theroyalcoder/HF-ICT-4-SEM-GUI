#include "Widget.h"

#include <QDebug>
#include <QPainter>
#include <QPaintEvent>
#include <QWidget>

Widget::Widget(QWidget *parent) : QWidget(parent) {
}

void Widget::paintEvent(QPaintEvent *event)
{
    qDebug() << "PaintEvent";
    QPainter painter(this);

    painter.drawRect(0, 0, width()-1, height()-1);
}
