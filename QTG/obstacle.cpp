#include "obstacle.h"
#include "gameobejct.h"
#include "constants.h"

#include <QImage>
#include <QDebug>

Obstacle::Obstacle(int x, int y)
    : GameObject(x, y,constants::ImgFolder + "obstacle.png", 105)
    ,up(true),down(false)
{
}

void Obstacle::move()
{
    if(up){
        if(y + 120 < 600){
            y +=5;
        }
        else{
            up = false;
            down = true;
        }
    }
    if(down){
    if(y > 0){
        y -=5;
    }
    else{
        down = false;
        up = true;
    }
    }

}
