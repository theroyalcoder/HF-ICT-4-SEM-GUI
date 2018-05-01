#include "obstacle.h"
#include "gameobejct.h"
#include "constants.h"

#include <QImage>
#include <QDebug>

Obstacle::Obstacle(int x, int y)
    : GameObject(x, y,constants::ImgFolder + "ballon.png", 105)
{
<<<<<<< HEAD
    //qDebug() << "Constructor Obstacle";
=======
>>>>>>> 4322297b1b2ff39c9f6a1bc7298c8efe14712cb6
}

void Obstacle::move()
{
//    todo: implement
}
