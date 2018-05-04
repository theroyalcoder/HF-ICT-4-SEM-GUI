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
#include <QVector>

using namespace std;

class GameArea : public QWidget
{
    Q_OBJECT
private:
    QVector<GameObject *> gameObjects;
    QImage *backgroundImg;
    CollisionDetection *collisionChecker;
    bool movement;
    int LifePlayers;
    int LifeOpponent;
    bool gamestart;

//    Verhindern, dass GameArea Objekte kopiert werden
    Q_DISABLE_COPY(GameArea)

public:
    GameArea(QWidget *parent = 0);
    ~GameArea();

//    GameArea(GameArea &obj) = delete;
//    GameArea& operator =(GameArea &obj) = delete;

    void paintEvent(QPaintEvent *event);
    void moven(int movement);
    void startGame();
    void shoot(int speed, int angle);
    int getWidth();
    int getHeight();
    void checkOnce();
    bool once;
public slots:
    void restarter();
    void lifeDeduction();
    void next();
signals:
    void gameFinished();
};

#endif // GAMEAREA_H
