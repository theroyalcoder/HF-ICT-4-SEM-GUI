#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

class MyWidget : public QWidget {
public:
    void paintEvent(QPaintEvent *event);
    MyWidget();
};

#endif // MYWIDGET_H
