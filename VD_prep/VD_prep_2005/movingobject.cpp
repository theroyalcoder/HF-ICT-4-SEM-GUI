#include "movingobject.h"

movingobject::movingobject(int x, int delay, QWidget *parent)
{

}

int movingobject::getY() const
{
    return y;
}

void movingobject::setY(int value)
{
    y = value;
}

int movingobject::getX() const
{
    return x;
}

void movingobject::setX(int value)
{
    x = value;
}

int movingobject::getDelay() const
{
    return delay;
}

void movingobject::setDelay(int value)
{
    delay = value;
}
