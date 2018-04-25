#ifndef GAMEAREA_H
#define GAMEAREA_H

#include <QImage>
#include <vector>
#include <QPaintEvent>
#include <QPainter>
#include <QImage>
#include <QString>
#include <QWidget>
using namespace std;

class GameArea : public QWidget
{
private:
    QImage *backgroundImg;
    //vector<GameObject *> gameObjects;
public:
    GameArea(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    void startGame();
    void shoot(int speed, int angle);
    void next();
protected:
    void gameFinished();
};

#endif // GAMEAREA_H
