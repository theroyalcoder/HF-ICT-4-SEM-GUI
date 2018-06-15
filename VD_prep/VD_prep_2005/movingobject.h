#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

#include <QWidget>
#include <QThread>

class movingobject : public QThread
{
protected:
    int delay;
    int x;
    int y;
    QWidget *parent;
    virtual void objectMoved() = 0;

public:
    movingobject(int x, int delay, QWidget *parent);
    int getWidth() const;
    int getHeight() const;

    int getDelay() const;
    void setDelay(int value);

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);
};

#endif // MOVINGOBJECT_H
