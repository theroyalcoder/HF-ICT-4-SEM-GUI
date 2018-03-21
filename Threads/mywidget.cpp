#include "mywidget.h"
#include <QObject>
#include <QPainter>
#include <QPushButton>
#include <QHBoxLayout>

MyWidget::MyWidget() {
    /*
    hlayout = new QHBoxLayout();
    startButton = new QPushButton("START");

    hlayout->addWidget(startButton);
    setLayout(hlayout);
    */
}

void MyWidget::PaintEvent(QPaintEvent *event) {
    //qDebug() << "PaintEvent";
    QPainter painter(this);
    //painter.setPen(QPen(Qt::black, 5));
    painter.drawLine(10, 80, 90, 20);

}
