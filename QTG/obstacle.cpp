#include "obstacle.h"
#include "gameobejct.h"
#include "constants.h"

#include <QImage>
#include <QDebug>

Obstacle::Obstacle(int x, int y)
    : GameObject(x, y,constants::ImgFolder + "ballon.png", 105)
{
    qDebug() << "Constructor Obstacle";
}

void Obstacle::move()
{
    //leer lassen (obstacle bewegt sich nicht)
}
