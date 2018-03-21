#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QDebug>

class MyWidget : public QWidget {
public:
    MyWidget();
    void PaintEvent(QPaintEvent *event);
};

#endif // MYWIDGET_H
