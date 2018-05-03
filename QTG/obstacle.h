#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "gameobejct.h"

class Obstacle : public GameObject
{
private:
    bool up;
    bool down;

public:
    Obstacle(int x, int y);
    virtual void move();
};

#endif // OBSTACLE_H
