#include "widget.h"

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
    painter.setPen(QPen(Qt::black, 5));
    //painter.drawRect(0, 0, width()-1, height()-1);

    float x = 0;
    float y = 0;

    float ax = width() * 0.05;
    float ay = height() * 0.05;

    float bx = width() * 0.95;
    float by = height() * 0.5;

    float cx = width() * 0.5;
    float cy = height() * 0.95;

    float mx = 0;
    float my = 0;

    QPoint A(10, 10);
    QPoint B(10, 10);
    QPoint C(10, 10);

    A.setX(ax);
    A.setY(ay);
    B.setX(bx);
    B.setY(by);
    C.setX(cx);
    C.setY(cy);

    painter.drawPoint(A);
    painter.drawPoint(B);
    painter.drawPoint(C);

    x = ax;
    y = ay;

    A.setX(x);
    A.setY(y);
    painter.drawPoint(A);

    int random = 0;
    int anzahl = 100000;

    for(int i = 0; i < anzahl; i++) {
        QPoint M(mx, my);
        painter.drawPoint(M);

        random = rand() % 3 + 1;

        switch(random) {
        case 1:
            mx = (ax + x) / 2;
            my = (ay + y) / 2;

                break;
        case 2:
            mx = (bx + x) / 2;
            my = (by + y) / 2;

                break;
        case 3:
            mx = (cx + x) / 2;
            my = (cy + y) / 2;

                break;
        default:
            qDebug() << "default";
            break;
        }
        x = mx;
        y = my;
    }

}
