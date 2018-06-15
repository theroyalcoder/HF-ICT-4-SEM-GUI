#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include <QPaintEvent>

class QPaintEvent;
class QWidget;

class gui
{
public:
    gui(QWidget *parent);
    void paintEvent(QPaintEvent *event);
};

#endif // GUI_H
