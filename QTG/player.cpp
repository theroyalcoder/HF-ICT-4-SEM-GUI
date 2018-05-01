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
    //    todo: implement
}
