#include "gameobejct.h"
#include "obstacle.h"
#include "player.h"
#include "shoot.h"

#include <QDebug>
#include <QPainter>
#include <QImage>

GameObject::GameObject(int x, int y, QString imgPath, int width)
{
<<<<<<< HEAD
    //qDebug() << "GameObject created";
=======
//    qDebug() << "GameObject created";
>>>>>>> 4322297b1b2ff39c9f6a1bc7298c8efe14712cb6

    this->setX(x);
    this->setY(y);

    QImage tmp(imgPath);
    img = new QImage(tmp.scaledToWidth(width));
}

void GameObject::paint(QPainter *painter)
{
    painter->drawImage(this->getX(), this->getY(), *img);
}

//Getter and Setter methods
int GameObject::getX() const {return x;}

void GameObject::setX(int value) {x = value;}

int GameObject::getY() const {return y;}

void GameObject::setY(int value) {y = value;}

int GameObject::width() {return img->width();}

int GameObject::height() {return img->height();}
