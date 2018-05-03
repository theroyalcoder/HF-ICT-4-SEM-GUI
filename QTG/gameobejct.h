#ifndef GAMEOBEJCT_H
#define GAMEOBEJCT_H

#include <QImage>
#include <QString>
#include <QPainter>

class GameObject
{
public:
    QImage *img;

    GameObject(int x, int y, QString imgPath, int width);
//    Wenn man den Kopierkonstruktor benutzen will, kommt eine Mledung, dass dieser auf delete gesetzt ist
    GameObject(GameObject &) = delete;
    GameObject& operator =(GameObject& ) = delete;
    virtual void move() = 0;

    void paint(QPainter *painter);

    void setRichtung(int richtung);
    int getRichtung();

    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);

    int width();
    int height();

protected:
    int x;
    int y;
    //erweitert
    int richtung;
    int widthGA;
    int heightGA;
};

#endif // GAMEOBEJCT_H
