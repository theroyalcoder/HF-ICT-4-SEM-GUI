#include "obstacle.h"
#include "gameobejct.h"

#include <QImage>
#include <QDebug>

Obstacle::Obstacle(int x, int y)
    : GameObject(x, y, "/Users/anuuthomson/QtProjects/HF-ICT-4-SEM-GUI/QTG/0_img/obstacle.png", 105)
{
    qDebug() << "Constructor Obstacle";
}

void Obstacle::move()
{
    //leer lassen (obstacle bewegt sich nicht)
}
