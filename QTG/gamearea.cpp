#include "gamearea.h"
#include "gameobejct.h"
#include "obstacle.h"
#include "player.h"
#include "shoot.h"
#include "thread.h"
#include "constants.h"
#include "collisiondetection.h"

#include <QDebug>
#include <QPainter>
#include <QWidget>
#include <QString>

GameArea::GameArea(QWidget *parent) : QWidget(parent)
{
    qDebug() << "GameArea Constructor";

    //Background
    QImage img(constants::ImgFolder + "background.gif");
    backgroundImg = new QImage(img.scaledToWidth(1000));

    //Thread
    Thread *t = new Thread();
    QObject::connect(t, SIGNAL(refresh()), this, SLOT(next()));
    t->start();
    qDebug() << "Thread started";
}

void GameArea::paintEvent(QPaintEvent *event)
{
//    Creating QPainter
    QPainter painter(this);

    //Draw background
    painter.drawImage(0, 0, *backgroundImg);

//    Draw gameObjects (Player, Obstacle)
    for (GameObject *x : gameObjects) {
        x->paint(&painter);
    }
}

void GameArea::startGame()
{
//    Create Player
    Player *player = new Player(0, 195);
    gameObjects.push_back(player);

    srand(time(NULL));

//    Create Obstacle Objects on a randomized place
    int x, y, w;
    w = width();
    x = rand() % (w / 4) + 3 * w / 4 - 50;
    y = rand() % (height() - 100) + 50;

    Obstacle *obst = new Obstacle(x, y);
    gameObjects.push_back(obst);

//    update
    this->update();
}

void GameArea::shoot(int speed, int angle)
{
//    Create Shoot Object and push back to the other GameObjects
    Shoot *shoot = new Shoot(150, 190, speed, angle);
    gameObjects.push_back(shoot);

    CollisionDetection *ka = new CollisionDetection();
    ka->check(shoot, shoot);
}

void GameArea::next()
{
//    going thru all Game Objects and execute move method
    for (int i = 0; i < gameObjects.size(); i++) {
        GameObject *go = gameObjects.at(i);
        go->move();
    }

//    update
    update();
}
