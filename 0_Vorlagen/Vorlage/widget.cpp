#include "widget.h"

#include <QPushButton>
#include <QGridLayout>
#include <QDebug>

#include "eventhandler.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    button = new QPushButton("EButton");
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(button, 0, 0);
    setLayout(layout);

    EventHandler *h = new EventHandler();
    QObject::connect(button, SIGNAL(clicked()), h, SLOT(onButtonClicked()));
    QObject::connect(h, SIGNAL(samplesignal(int)), this, SLOT(mySampleSlot(int)));
}

Widget::~Widget()
{

}

void Widget::mySampleSlot(int v)
{
    qDebug() << v;
}
