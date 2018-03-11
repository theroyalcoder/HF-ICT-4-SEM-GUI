#include "mywidget.h"
#include <QPainter>
#include <QDebug>

MyWidget::MyWidget() {
}

void MyWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.drawLine(20, 20, 100, 125);
    qDebug() << "DEBUG";
}
