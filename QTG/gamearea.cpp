#include "gamearea.h"

#include <QPainter>
#include <QDebug>
#include <QWidget>

GameArea::GameArea(QWidget *parent) : QWidget(parent)
{
    qDebug() << "Load background";

    QImage img("/Users/anuuthomson/QtProjects/HF-ICT-4-SEM-GUI/QTG/background.gif");

    //QImage img("file:///Users/anuuthomson/QtProjects/HF-ICT-4-SEM-GUI/QTG/background.jpg");
    backgroundImg = new QImage(img.scaledToWidth(1000));
}

void GameArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(0, 0, *backgroundImg);
}

void GameArea::startGame()
{

}

void GameArea::shoot(int speed, int angle)
{

}

void GameArea::next()
{

}
