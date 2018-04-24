#include "mainwidget.h"
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
#include <QInputDialog>

void MainWidget::createObjects()
{
    //1. Create Objects
    qDebug() << "Create Objects";
    titleLabel = new QLabel("<h1>QTG</h1>");
    shootsLabel = new QLabel("#Shoots");

    in_shoots = new QInputDialog();
    in_speed = new QInputDialog();
    in_angle = new QInputDialog();

    actionButton = new QPushButton("Start");
    speedSlider = new QSlider(Qt::Horizontal);
    angleSlider = new QSlider(Qt::Horizontal);
}

void MainWidget::createLayout()
{
    qDebug() << "Create Layout";
    //2. Create Layout
    QVBoxLayout *vAll = new QVBoxLayout();
    QHBoxLayout *hTitle = new QHBoxLayout();
    QHBoxLayout *hGameArea = new QHBoxLayout();
    QHBoxLayout *hBottom = new QHBoxLayout();

    hTitle->addWidget(titleLabel);
    hBottom->addWidget(actionButton);
    hBottom->addWidget(shootsLabel);
    hBottom->addWidget(in_shoots);
    hBottom->addWidget(speedSlider);
    hBottom->addWidget(in_speed);
    hBottom->addWidget(angleSlider);
    hBottom->addWidget(in_angle);

    vAll->addLayout(hTitle);
    vAll->addLayout(hGameArea);
    vAll->addLayout(hBottom);

    //hGameArea->setAlignment(parent, Qt::AlignTop);
    //vAll->setAlignment(parent, Qt::AlignTop);

    //3. Set Main Layout
    setLayout(vAll);

}

void MainWidget::connectObjects()
{
    qDebug() << "Connect Layout";
}

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    qDebug() << "START";

    createObjects();
    createLayout();
    connectObjects();
}

void MainWidget::speedSliderMoved(int)
{

}

void MainWidget::angleSliderMoved(int)
{

}

void MainWidget::actionButtonClicked(int)
{

}
