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

GameArea::GameArea(QWidget *parent) : QWidget(parent)/**/
{

    //
    ka = new CollisionDetection();
    //qDebug() << "GameArea Constructor";
    bewegung = false;
    //Background
    QImage img(constants::ImgFolder + "background.gif");
    backgroundImg = new QImage(img.scaledToWidth(1000));

    //Thread
    Thread *t = new Thread(35);
    Thread *s = new Thread(300);
    t->start();
    s->start();
    QObject::connect(t, SIGNAL(refresh()), this, SLOT(next()));
    QObject::connect(s, SIGNAL(refresh()), this, SLOT(mover()));

    //qDebug() << "Thread started";
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

    if(gamestart){
    //Draw Lebensanzeige
    painter.setPen(QPen(Qt::black,20));
    painter.drawLine(50,70,350,70);
    //leben
    painter.setPen(QPen(Qt::red,15));
    painter.drawLine(50,70,LebenSpieler+50,70);

    painter.setPen(QPen(Qt::black,20));
    painter.drawLine(620,70,920,70);
    painter.setPen(QPen(Qt::red,15));
    painter.drawLine(620,70,LebenGegner+620,70);
}
    update();
}
void GameArea::mover(){
    //bewegung = false;
    LebenSpieler -= 5;
}

void GameArea::moven(int richtung)
{
//Player mover
    gameObjects.at(0)->setRichtung(richtung);
}

void GameArea::startGame()
{
    gamestart = true;
    LebenSpieler = 300;
    LebenGegner = 300;
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
    bool getroffen = false;
//    going thru all Game Objects and execute move method
    for (int i = 0; i < gameObjects.size(); i++) {
        GameObject *go = gameObjects.at(i);
        update();
        if(i >= 2){
            if(i != 0 || i != 1){
                getroffen = ka->check(gameObjects.at(i), gameObjects.at(1));
            }
            if(getroffen){
                LebenGegner -= 10;

                //gameObjects.erase(gameObjects.begin()+2);

            //qDebug() << "getroffen";
            }
            if(ka->outOfRange(gameObjects.at(i),height(),width())){
                //qDebug() << "out of range";
                gameObjects.erase(gameObjects.begin()+2);
            }
        }
        if(LebenGegner <= 0){
            //gameFinished();
            qDebug() << "gewonnen";
        }

        else if(LebenSpieler <= 0){
            //gameFinished();
            qDebug() << "verloren";
        }

        update();
        go->move();
}

//    update
    update();
}


/*
QMessageBox::StandardButton reply;
  reply = QMessageBox::question(this, "Test", "Quit?",
                                QMessageBox::Yes|QMessageBox::No);
  if (reply == QMessageBox::Yes) {
    qDebug() << "Yes was clicked";
    QApplication::quit();
  } else {
    qDebug() << "Yes was *not* clicked";
  }
}
*/
