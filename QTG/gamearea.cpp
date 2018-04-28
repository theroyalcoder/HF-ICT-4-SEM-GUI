#include "gamearea.h"
#include "gameobejct.h"
#include "obstacle.h"
#include "player.h"
#include "shoot.h"
#include "thread.h"

#include <QDebug>
#include <QPainter>
#include <QWidget>

GameArea::GameArea(QWidget *parent) : QWidget(parent)
{
    qDebug() << "Load background";

    //Background
    QImage img("/Users/anuuthomson/QtProjects/HF-ICT-4-SEM-GUI/QTG/0_img/background.gif");
    backgroundImg = new QImage(img.scaledToWidth(1000));

    Obstacle *obst = new Obstacle(700, 20);
    Player *play = new Player(10, 200);

    gameObjects.push_back(obst);
    gameObjects.push_back(play);

    Thread *t = new Thread();

    QObject::connect(
                t, SIGNAL(refresh()),
                this, SLOT(next()));

    t->start();

}

void GameArea::paintEvent(QPaintEvent *event)
{
    qDebug() << "GameArea paintEvent started";

    painter = new QPainter(this);

    //Draw background
    painter->drawImage(0, 0, *backgroundImg);

    for (int i = 0; i < gameObjects.size(); i++) {
        GameObject *go = gameObjects.at(i);
        go->paint(painter);
    }
}

void GameArea::startGame()
{

}

void GameArea::shoot(int speed, int angle)
{    
    Shoot *weapon = new Shoot(150, 190, speed, angle);
    gameObjects.push_back(weapon);
    weapon->paint(painter);
}

void GameArea::next()
{
    qDebug() << "next";
    // Durch alle GameObjects durchgehen und move() ausführen


//    update();
}
