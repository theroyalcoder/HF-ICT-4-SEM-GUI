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

GameArea::GameArea(QWidget *parent) : QWidget(parent), gamestart(false), once(false)
{
    collisionControl = new CollisionDetection();
    movement = false;

    //Background
    QImage img(constants::ImgFolder + "background.gif");
    backgroundImg = new QImage(img.scaledToWidth(1000));

    //Thread
    Thread *t = new Thread(35);
    Thread *s = new Thread(300);
    t->start();
    s->start();
    QObject::connect(t, SIGNAL(refresh()), this, SLOT(next()));
    QObject::connect(s, SIGNAL(refresh()), this, SLOT(lifeDeduction()));

}

void GameArea::paintEvent(QPaintEvent *event)
{
    update();

//    Creating QPainter
    QPainter painter(this);

    //Draw background
    painter.drawImage(0, 0, *backgroundImg);

//    Draw gameObjects (Player and Obstacle)
    for (GameObject *x : gameObjects) {
        x->paint(&painter);
    }

    if(gamestart){
    //Draw Lebensanzeige
    painter.setPen(QPen(Qt::black,20));
    painter.drawLine(50,70,350,70);

    //leben
    painter.setPen(QPen(Qt::red,15));
    painter.drawLine(50,70,LifePlayers+50,70);

    painter.setPen(QPen(Qt::black,20));
    painter.drawLine(620,70,920,70);
    painter.setPen(QPen(Qt::red,15));
    painter.drawLine(620,70,LifeOpponent+620,70);
}
    update();
}
void GameArea::lifeDeduction(){
    LifePlayers -= 1;
}

void GameArea::moven(int direction)
{
//Player mover
    gameObjects.at(0)->setDirection(direction);
}

void GameArea::startGame()
{
    gamestart = true;
    LifePlayers = 300;
    LifeOpponent = 300;

//    Create Player
    Player *player = new Player(0, 335,0,height());
    gameObjects.push_back(player);

    srand(time(NULL));

//    Create Obstacle Objects on a randomized place
    int x, y, w;
    w = width();
    x = rand() % (w / 4) + 3 * w / 4 - 50;
    y = rand() % (height() - 100) + 50;

    //Obstacle *obst = new Obstacle(x, y);
    Obstacle *obst = new Obstacle(850, 200);
    gameObjects.push_back(obst);

//    update
    this->update();
}

void GameArea::shoot(int speed, int angle)
{
//    Create Shoot Object and push back to the other GameObjects
    Shoot *shoot = new Shoot(gameObjects.at(0)->getX()+120, gameObjects.at(0)->getY(), speed, angle);
    gameObjects.push_back(shoot);
}

void GameArea::restarter()
{
    once = false;
    gamestart = false;
    gameObjects.clear();
}

GameArea::~GameArea()
{
    //delete this;
}

int GameArea::getWidth() {return width();}

int GameArea::getHeight() {return height();}

void GameArea::checkOnce()
{
    if(once) {gameFinished();}
}

void GameArea::next()
{
    int count = 0;

    if(!once){
//    going thru all Game Objects and execute move method
    for (GameObject *gameObject : gameObjects) {
        GameObject *go = gameObject;

        if(count == 2){
            if(collisionControl->check(gameObject, gameObjects.at(1))){
                LifeOpponent -= 5;
            }

            if(collisionControl->outOfRange(gameObject, height(), width())){
                //qDebug() << "out of range";
                gameObjects.erase(gameObjects.begin()+2);
            }

            if(LifeOpponent <= 0){
                once = true;
                gameFinished();
                qDebug() << once;
                //checkOnce();

            }

            if(LifePlayers <= 0){
                once = true;
                gameFinished();
            }
        }
        update();
        go->move();

        count++;
    }
}
//    update
    update();
}
