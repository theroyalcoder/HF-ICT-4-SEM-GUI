#include "player.h"
#include "gameobejct.h"
#include "constants.h"
#include <QDebug>

Player::Player(int x, int y, int richtung, int heightGA)
    : GameObject(x, y, constants::ImgFolder + "player.png", 250)
{
//player.jpg
}

void Player::move()
{
    if(richtung == 1){
        if(y+7 <=  340 ){
        y = y+5;
        }
    }
    if(richtung == 2){
        if(y-7 >=  -heightGA+120){
             y = y-5;
        }
    }
}
