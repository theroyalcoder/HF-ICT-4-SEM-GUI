#include "player.h"
#include "gameobejct.h"
#include "constants.h"

Player::Player(int x, int y)
    : GameObject(x, y, constants::ImgFolder + "player.png", 250)
{
//player.jpg
}

void Player::move()
{
    /*
    if(richtung == 1){
        //int neuy = gameObjects.at(0)->getY();
        //gameObjects.at(0)->setY(neuy+5);
    }
    if(richtung == 2){
        int neuy = gameObjects.at(0)->getY();
        gameObjects.at(0)->setY(neuy-5);
    }
    */
    //    todo: implement
}
