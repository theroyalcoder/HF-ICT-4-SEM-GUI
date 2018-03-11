#include "eventhandler.h"
#include "creditcardgui.h"

#include <QDebug>

eventhandler::eventhandler(CreditCardGUI *parent) : parent(parent)
{

}

void eventhandler::onCheckButtonClicked()
{
    //QDebug() << "hallo";
    //QDebug() << parent->getBlock1();
}

