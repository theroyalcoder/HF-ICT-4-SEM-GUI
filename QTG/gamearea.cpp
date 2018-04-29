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
    qDebug() << "GameArea Constructor";

    //Background
    QImage img("/Users/anuuthomson/QtProjects/HF-ICT-4-SEM-GUI/QTG/0_img/background.gif");
    backgroundImg = new QImage(img.scaledToWidth(1000));

    Thread *t = new Thread();

    QObject::connect(t, SIGNAL(refresh()), this, SLOT(next()));

    t->start();
    qDebug() << "Thread started";
}

void GameArea::paintEvent(QPaintEvent *event)
{
    qDebug() << "GameArea paintEvent started";
    QPainter painter(this);

    //Draw background
    painter.drawImage(0, 0, *backgroundImg);

    for (GameObject *x : gameObjects) {
        x->paint(&painter);
    }


//    for (int i = 0; i < gameObjects.size(); i++) {
//        GameObject *go = gameObjects.at(i);
//        go->paint(painter);
//    }
}

void GameArea::startGame()
{
    Player *player = new Player(0, 195);
    gameObjects.push_back(player);

    int x, y, w;
    w = width();
    x = rand() % (w / 4) + 3 * w / 4 - 50;
    y = rand() % (height() - 100) + 50;

    Obstacle *obst = new Obstacle(x, y);
    gameObjects.push_back(obst);

    this->update();
}

void GameArea::shoot(int speed, int angle)
{
    Shoot *shoot = new Shoot(150, 190, speed, angle);
    gameObjects.push_back(shoot);
}

void GameArea::next()
{
    for (int i = 0; i < gameObjects.size(); i++) {
        GameObject *go = gameObjects.at(i);
        go->move();
    }
    update();
}
