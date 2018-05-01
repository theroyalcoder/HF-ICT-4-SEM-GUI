#include "obstacle.h"
#include "gameobejct.h"
#include "constants.h"
#include "gamearea.h"

#include <QImage>
#include <QDebug>

Obstacle::Obstacle(int x, int y)
    : GameObject(x, y,constants::ImgFolder + "obstacle.png", 105)
,rauf(true),runter(false)
{
}

void Obstacle::move()
{
    GameArea ga;
    if(rauf){
        if(y + 120 < ga.getHeight()){
            y +=5;
        }
        else{
            rauf = false;
            runter = true;
        }
    }
    if(runter){
    if(y > 0){
        y -=5;
    }
    else{
        runter = false;
        rauf = true;
    }
    }

}
