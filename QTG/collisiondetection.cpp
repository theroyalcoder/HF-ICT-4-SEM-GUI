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
    int Hwidth = go1->width();
    int Hheight = go1->height();

    //Gegner
    int Gx = go2->getX();
    int Gy = go2->getY();
    int Gwidth = go1->width();
    int Gheight = go1->height();
/*
    if((Hx + Hwidth) > Gx){
        qDebug() << "getroffen";
        if(Hy < Gy+Gheight && (Hy + Hheight) > Gy){
             return true;
        }
        //Achtungnacher rausnehmen
        return true;
        //
    }
*/
    return false;
}
