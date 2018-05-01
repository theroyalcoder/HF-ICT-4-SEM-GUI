#include "collisiondetection.h"
#include "gameobejct.h"
#include "obstacle.h"
#include "player.h"
#include "shoot.h"

#include <QDebug>

CollisionDetection::CollisionDetection()
{

}

bool CollisionDetection::check(GameObject *go1, GameObject *go2)
{
    //Hadouken
    int Hx = go1->getX();
    int Hy = go1->getY();
    int Hwidth = 100;
    int Hheight =  100;

    //Gegner
    int Gx = go2->getX();
    int Gy = go2->getY();

    int Gwidth =  80;
    int Gheight = 100;

    if(((((Hx + Hwidth)) > Gx) && (Hx < (Gx+Gwidth)))){
        if(((Hy < (Gy+Gheight)) && ((Hy + Hheight) > Gy))){
             //qDebug() << "getroffen";
             return true;
        }
    }
    return false;
}

bool CollisionDetection::outOfRange(GameObject *go1)
{
    int Hx = go1->getX();
    int Hy = go1->getY();

    if(Hx > 1000 && Hy > 1000){
        return true;
    }
    else if(Hx > 1000+ 2000){
        return true;
    }
    else if((Hy > 1000+ 2000))
    return false;
}
