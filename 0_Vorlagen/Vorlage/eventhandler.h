#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QObject>

class EventHandler : public QObject
{
    Q_OBJECT

public:
    EventHandler();

public slots:
    void onButtonClicked();

signals:
    void samplesignal(int v); // DO NOT IMPLEMENT
};

#endif // EVENTHANDLER_H
