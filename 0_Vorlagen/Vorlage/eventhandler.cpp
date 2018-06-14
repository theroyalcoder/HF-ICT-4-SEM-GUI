#include "eventhandler.h"

#include <QDebug>

EventHandler::EventHandler()
{

}

void EventHandler::onButtonClicked()
{
    qDebug() << "Judihui...";

    // Signal ausloesen
    emit samplesignal(123);
}
