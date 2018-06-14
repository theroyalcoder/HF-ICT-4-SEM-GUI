#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QPushButton;

class Widget : public QWidget
{
    Q_OBJECT

private:
    QPushButton *button;

public:
    Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void mySampleSlot(int v);
};

#endif // WIDGET_H
