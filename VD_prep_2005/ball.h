#ifndef BALL_H
#define BALL_H

#include "movingobject.h"

#include <QWidget>

class ball : public movingobject
{
public:
    ball(int x, int y, int delay, QWidget *parent);

    void run();
    int getWidth() const;
    int getHeight() const;
};

#endif // BALL_H
