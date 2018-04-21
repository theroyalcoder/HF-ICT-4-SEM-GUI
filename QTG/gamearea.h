#ifndef GAMEAREA_H
#define GAMEAREA_H

#include <QImage>
#include <vector>
#include <QPaintEvent>
using namespace std;

class GameArea
{
private:
    QImage *backgrounding;
    //vector<GameObject *> gameObjects;
public:
    GameArea();
    void paintEvent(QPaintEvent *event);
    void startGame();
    void shoot(int speed, int angle);
    void next();
protected:
    void gameFinished();
};

#endif // GAMEAREA_H
