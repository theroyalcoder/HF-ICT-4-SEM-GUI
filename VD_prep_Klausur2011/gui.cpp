#include "gui.h"
#include "paintarea.h"

#include <QDebug>
#include <QHBoxLayout>
#include <QVBoxLayout>

Gui::Gui()
{
    PaintArea *pa = new PaintArea();
    pa->setFixedSize(500, 500);
    pa->show();

    QVBoxLayout *vBox = new QVBoxLayout();
    vBox->addWidget(pa);

    setLayout(vBox);
}


Gui::~Gui(){}

void Gui::onGoButtonPressed()
{

}

void Gui::onResetButtonPressed()
{

}
