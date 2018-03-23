#ifndef KUNST_H
#define KUNST_H

#include <QWidget>
#include <QPaintEvent>

class QPaintEvent;

class Kunst : public QWidget
{
    Q_OBJECT
public:
    Kunst(QWidget *parent = 0);
    void kunstEvent(QPaintEvent *event);
};

#endif // KUNST_H
