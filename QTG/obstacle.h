#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "gameobejct.h"

class Obstacle : public GameObject
{
private:
    bool rauf;
    bool runter;
public:
    Obstacle(int x, int y);
    virtual void move();
};

#endif // OBSTACLE_H
