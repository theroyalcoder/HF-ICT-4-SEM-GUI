#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QObject>

class EventHandler : public QObject {

    Q_OBJECT

public slots:
    void mySlot();

public:
    EventHandler();
};

#endif // EVENTHANDLER_H
