#ifndef GAMEAREA_H
#define GAMEAREA_H

#include <QImage>
#include <vector>
#include <QPaintEvent>
#include <QPainter>
#include <QImage>
#include <QString>
#include <QWidget>

#include "obstacle.h"
#include "player.h"
#include "shoot.h"

using namespace std;

class GameArea : public QWidget
{
    Q_OBJECT
private:
    QImage *backgroundImg;
    vector<GameObject *> gameObjects;
    bool bewegung;

public:
    GameArea(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    void moven(int richtung);
    void startGame();
    void shoot(int speed, int angle);
    //
    int getWidth();
    int getHeight();

protected:
    void gameFinished();

public slots:
    void mover();
    void next();
};

#endif // GAMEAREA_H
