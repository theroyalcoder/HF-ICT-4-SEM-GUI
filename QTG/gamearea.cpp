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
#include <QMediaPlayer>

GameArea::GameArea(QWidget *parent) : QWidget(parent)
{
    //qDebug() << "GameArea Constructor";
    bewegung = false;

    //Background
    QImage img(constants::ImgFolder + "background.gif");
    backgroundImg = new QImage(img.scaledToWidth(1000));

    // play background music
    QMediaPlayer *bgm = new QMediaPlayer();
    bgm->setMedia(QUrl("qrc:/sounds/1_audio/start.mp3"));
    bgm->play();

    //Thread
    Thread *t = new Thread(35);
    Thread *s = new Thread(200);
    QObject::connect(t, SIGNAL(refresh()), this, SLOT(next()));
    QObject::connect(s, SIGNAL(refresh()), this, SLOT(mover()));
    t->start();
}

void GameArea::paintEvent(QPaintEvent *event)
{
    update();

//    Creating QPainter
    QPainter painter(this);

    //Draw background
    painter.drawImage(0, 0, *backgroundImg);

//    Draw gameObjects (Player, Obstacle)
    for (GameObject *x : gameObjects) {
        x->paint(&painter);
    }

    update();
}
void GameArea::mover(){
    //bewegung = false;
}

void GameArea::moven(int richtung)
{

    if(richtung == 1){
        //down
        int neuy = gameObjects.at(0)->getY();
        if(neuy+7 <=  height() -200 ){
            gameObjects.at(0)->setY(neuy+7);
        }

    }

    if(richtung == 2){
        //up
        int neuy = gameObjects.at(0)->getY();
        if(neuy+7 >=  10){
        gameObjects.at(0)->setY(neuy-7);
        }
    }
}

void GameArea::startGame()
{
//    Create Player
    Player *player = new Player(0, 335);
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

int GameArea::getWidth()
{
    return width();
}

int GameArea::getHeight()
{
    return height();
}

void GameArea::next()
{
    CollisionDetection *ka = new CollisionDetection();

//    going thru all Game Objects and execute move method
    for (int i = 0; i < gameObjects.size(); i++) {
        GameObject *go = gameObjects.at(i);

        if(i >= 2){
            if(ka->check(gameObjects.at(i), gameObjects.at(1))){

//                gameObjects.erase(gameObjects.begin()+2);

//                emit gameFinished();

//                qDebug() << "    ";
            }
            if(ka->outOfRange(gameObjects.at(i))){
                gameObjects.erase(gameObjects.begin()+2);
            }
        }
        go->move();
}

//    update
    update();
}
