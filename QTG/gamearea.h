#ifndef GAMEAREA_H
#define GAMEAREA_H

#include <QImage>
#include <vector>
#include <QPaintEvent>
#include <QPainter>
#include <QImage>
#include <QString>
#include <QWidget>

#include "collisiondetection.h"
#include "obstacle.h"
#include "player.h"
#include "shoot.h"
#include "thread.h"

using namespace std;

class GameArea : public QWidget
{
    Q_OBJECT
private:
    QImage *backgroundImg;
    vector<GameObject *> gameObjects;    
    CollisionDetection *ka;

    bool bewegung;
    int LebenSpieler;
    int LebenGegner;
    bool gamestart;
    bool once;



public:
    GameArea(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    void moven(int richtung);
    void startGame();
    void shoot(int speed, int angle);

    void restarter();
    GameArea(GameArea &) = delete;
    ~GameArea();
    GameArea& operator =(GameArea& ) = delete;
    //
    int getWidth();
    int getHeight();
    void checkOnce();
public slots:
    void mover();
    void next();

signals:
    void gameFinished();
};

#endif // GAMEAREA_H
