#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

class Widget;

class Eventhandler : public QObject {
    Q_OBJECT
private:
    Widget *parent;
public:
    Eventhandler(Widget *parent);
public slots:
    void onButtonClicked();
};

#endif // EVENTHANDLER_H
