#ifndef PLAYER_H
#define PLAYER_H

#include "gameobejct.h"

class Player : public GameObject
{
private:

public:
    Player(int x, int y, int richtung, int heightGA);
    virtual void move();
};

#endif // PLAYER_H
