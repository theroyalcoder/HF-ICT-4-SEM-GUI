#include "ball.h"


ball::ball(int x, int y, int delay, QWidget *parent)
{
//movingobject(int x, int delay, QWidget *parent);
//    movingobject *mo = new movingobject(1, 2, 3, this);
    ball *mo = new ball(1, 2, 3, this);
}

void ball::run()
{

}

int ball::getWidth() const
{

}

int ball::getHeight() const
{

}
