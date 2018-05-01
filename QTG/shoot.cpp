#include "shoot.h"
#include "gameobejct.h"
#include "constants.h"

#include <cmath>
#include <QDebug>

Shoot::Shoot(int x, int y, int speed, int angle)
    : GameObject(x, y,constants::ImgFolder + "banana.png", 100)
{
    t = 0;
    this->speed = speed;
    this->angle = angle;
}

void Shoot::move()
{
    //qDebug() << "angle" << angle;
    //qDebug() << "speed" << speed;
    //qDebug() << "t" << t;

    const double g = 9.81;
    double rad = 3.1415926 / 180 * angle;
    int dx = speed / 3 * cos(rad) * t;
    int dy = speed / 3 * sin(rad) * t - (g / 2) * pow(t,2);
    t = t + 0.1;
    x = x + dx/2;
    y = y - dy/2;
}
