#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QPaintEvent;

class widget : public QWidget {

    Q_OBJECT

public:
    widget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
};

#endif // WIDGET_H
