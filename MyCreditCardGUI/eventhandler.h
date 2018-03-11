#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QObject>
#include <QDebug>

class CreditCardGUI;

class eventhandler : public QObject
{
Q_OBJECT
private:
    CreditCardGUI *parent;

public:
    eventhandler(CreditCardGUI *parent);

public slots:
    void onCheckButtonClicked();

};

#endif // EVENTHANDLER_H
