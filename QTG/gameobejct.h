#ifndef GAMEOBEJCT_H
#define GAMEOBEJCT_H

#include <QImage>
#include <QString>
#include <QPainter>

class GameObject
{
public:
    GameObject(int x, int y, QString imgPath, int width);
    virtual void move() = 0;
    void paint(QPainter *painter);

    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);

    int width();
    int height();

    QImage *img;

protected:
    int x;
    int y;
};

#endif // GAMEOBEJCT_H
