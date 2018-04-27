#include "mainwidget.h"
#include "gamearea.h"

#include <string>
#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QDebug>
#include <QSlider>
#include <QPaintEvent>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    qDebug() << "Create MainWidget";
    ga = new GameArea(parent);

    createObjects();
    createLayout();
    connectObjects();
}

void MainWidget::createObjects()
{
    //1. Create Objects
    qDebug() << "Create Objects";
    titleLabel = new QLabel("<h1>QTG</h1>");
    titleLabel->setGeometry(0, 0, 10, 10);

    shootsLabel = new QLabel("#Shoots:");
    speedLabel = new QLabel("Speed:");
    angleLabel = new QLabel("Angle:");

    numberOfShotsInput = new QLineEdit();

    speedInput = new QLineEdit();
    speedInput->setText("1");

    angleInput = new QLineEdit();
    angleInput->setText("0");

    actionButton = new QPushButton("Start");

    speedSlider = new QSlider(Qt::Horizontal);
    speedSlider->setMinimum(1);
    speedSlider->setMaximum(100);

    angleSlider = new QSlider(Qt::Horizontal);
    angleSlider->setMinimum(0);
    angleSlider->setMaximum(90);
}

void MainWidget::createLayout()
{
    qDebug() << "Create Layout";

    //2. Create Layout
    QVBoxLayout *vAll = new QVBoxLayout();
    QVBoxLayout *vGameArea = new QVBoxLayout();
    QHBoxLayout *hBottom = new QHBoxLayout();

    //Adds the Backgroudimage and everything else from a gameare object
    vAll->addWidget(titleLabel);

    vGameArea->addWidget(ga);

    //Das Widget ga bekommt am meisten Platz und andere schrumpfen zusammen so viel wie es geht
    ga->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    hBottom->addWidget(actionButton);
    hBottom->addWidget(shootsLabel);
    hBottom->addWidget(numberOfShotsInput);
    hBottom->addWidget(speedLabel);
    hBottom->addWidget(speedSlider);
    hBottom->addWidget(speedInput);
    hBottom->addWidget(angleLabel);
    hBottom->addWidget(angleSlider);
    hBottom->addWidget(angleInput);

    vAll->addLayout(vGameArea);
    vAll->addLayout(hBottom);

    //3. Set Main Layout
    this->setLayout(vAll);
}

void MainWidget::connectObjects()
{
    qDebug() << "Connect Objects";

    //Speedsilder
    QObject::connect(
                speedSlider, SIGNAL(valueChanged(int)),
                this, SLOT(setSpeedInputValue(int)));

    //angleslider
    QObject::connect(
                angleSlider, SIGNAL(valueChanged(int)),
                this, SLOT(setAngleInputValue(int)));

    //actionbutton
    QObject::connect(
                actionButton, SIGNAL(clicked()),
                this, SLOT(setActionButtonValue()));
}

void MainWidget::speedSliderMoved(int value)
{
    qDebug() << "speedSliderMoved" << endl;
    qDebug() << value;
}

void MainWidget::angleSliderMoved(int value)
{
    qDebug() << "angleSliderMoved" << endl;
    qDebug() << value;

}

void MainWidget::actionButtonClicked()
{
    qDebug() << "actionButtonClicked" << endl;
    actionButton->setText("Shoot");

    numberOfShots = numberOfShots + 1;
    numberOfShotsInput->setText(numberOfShots);
}

void MainWidget::setSpeedInputValue(int v)
{
    qDebug() << "setSpeedInputValue";

    QString s = QString::number(v);
    speedInput->setText(s);
}

void MainWidget::setAngleInputValue(int v)
{
    qDebug() << "setAngleInputValue";

    QString s = QString::number(v);
    angleInput->setText(s);
}

void MainWidget::setActionButtonValue()
{
    qDebug() << "MainWidget - setActionButtonValue";
    static int count = -1;

    actionButton->setText("Shoot");

    count++;
    numberOfShotsInput->setText(QString::number(count));

    qDebug() << "MainWidget - start Game";
    ga->startGame();

}
