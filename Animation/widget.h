#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QPaintEvent;

namespace Ui {
class Widget;
}

class Widget : public QWidget {
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void paintEvent(QPaintEvent *event);
private:
    Ui::Widget *ui;
    int x, y, xSpeed, ySpeed;

public slots:
    void move();
};

#endif // WIDGET_H
