#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QObject>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

class Eventhandler : public QObject {
    Q_OBJECT
private:

public:
    Eventhandler();
public slots:
    void mySlot();
};

#endif // EVENTHANDLER_H
