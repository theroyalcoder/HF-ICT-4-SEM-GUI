#include "gui.h"
#include "paintarea.h"

#include <QDebug>
#include <QHBoxLayout>
#include <QVBoxLayout>

Gui::Gui()
{
//    1. Create Objects
    pa   = new PaintArea();
    pa->setNumberOfPoints(rand() % 1000);

    qDebug() << "result" << pa->getResult();

    QLabel *titel   = new QLabel("<h1>Shooting Gallery</h1>");
    QLabel *text    = new QLabel("Number of Points");

    numberInput     = new QLineEdit();
    goButton        = new QPushButton("GO");
    resetButton     = new QPushButton("RESET");
    resultLabel     = new QLabel("res");

    srand(static_cast<unsigned int>(time(nullptr)));

//    2. Create Layout
    QVBoxLayout *blau        = new QVBoxLayout();
    QHBoxLayout *rot         = new QHBoxLayout();
    QHBoxLayout *dunkelblau  = new QHBoxLayout();
    QHBoxLayout *gelb        = new QHBoxLayout();
    QVBoxLayout *gruen       = new QVBoxLayout();
    QVBoxLayout *orange      = new QVBoxLayout();

    rot->addWidget(titel);
    dunkelblau->addWidget(text);
    dunkelblau->addWidget(numberInput);
    gelb->addWidget(goButton);
    gelb->addWidget(resetButton);
    gruen->addWidget(pa);
    orange->addWidget(resultLabel);

    blau->addLayout(rot);
    blau->addLayout(dunkelblau);
    blau->addLayout(gelb);
    blau->addLayout(gruen);
    blau->addLayout(orange);

//    3. Set Layout
    setLayout(blau);
    pa->setFixedSize(500, 500);
    pa->show();

    QObject::connect(goButton, SIGNAL(clicked()),
    this, SLOT(onGoButtonPressed()));

    QObject::connect(resetButton, SIGNAL(clicked()),
    this, SLOT(onResetButtonPressed()));
}

Gui::~Gui(){}

void Gui::onGoButtonPressed()
{
    qDebug() << "GO";
    QString str = numberInput->text();
    pa->setNumberOfPoints(str.toDouble());

    qDebug() << "result" << pa->getResult();
}

void Gui::onResetButtonPressed()
{
    qDebug() << "RESET";
    pa->setResetFlag(false);
//    qDebug << numberInput->
}
