#include "eventhandler.h"
#include "widget.h"

Eventhandler::Eventhandler(Widget *parent) : parent(parent)
{

}

void Eventhandler::onButtonClicked()
{
    parent->inputLine->clear();
    //parent->getInputLine()->clear();
}
