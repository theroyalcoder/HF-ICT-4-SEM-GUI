#include "widget.h"
#include "ui_widget.h"
#include "thread.h"

#include <QThread>
#include <QPaintEvent>
#include <QPainter>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget), x(100), y(100), xSpeed(6), ySpeed(6) {
    ui->setupUi(this);

    Thread *t = new Thread();
    t->start();

    //Slots und Signals
    QObject::connect(t, SIGNAL(doSomething()), this, SLOT(move()));
    QObject::connect(t, SIGNAL(doSomething()), this, SLOT(update()));
}

Widget::~Widget() {
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.drawArc(x, y, 40, 40, 0, 5760);
}

void Widget::move() {
    int RADIUS = 40;
    x = x + xSpeed;
    y = y + ySpeed;

    if (x + RADIUS > width() || x < 0) {
        xSpeed *= -1;
    }

    if(y + RADIUS > height() || y < 0) {
        ySpeed *= -1;
    }

}
