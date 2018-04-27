#include "gamearea.h"
#include "gameobejct.h"
#include "obstacle.h"
#include "player.h"
#include "shoot.h"

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
    Shoot *weapon = new Shoot(150, 190, 1, 2);

    gameObjects.push_back(obst);
    gameObjects.push_back(play);
    gameObjects.push_back(weapon);
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
//    Shoot *shoo = new Shoot(20, 200, speed, angle);
//    shoo->paint(painter);
}

void GameArea::next()
{

}
