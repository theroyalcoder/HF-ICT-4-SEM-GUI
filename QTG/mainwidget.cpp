#include "mainwidget.h"
#include "mainwindow.h"
#include "gamearea.h"
#include "thread.h"
#include "constants.h"

#include <QAction>
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
#include <QtMultimedia/QSound>
#include <QMediaPlayer>
#include <QUrl>
#include <QMessageBox>
#include <QApplication>

MainWidget::MainWidget(QWidget *parent, int speed, int angle)
    : QWidget(parent), speed(0), angle(0), restart(false)
{
    ga = new GameArea(parent);
    init = true; // Init
    numberOfShots = 0;

//    Initialisation of shootSound
    shootSound = new QMediaPlayer();
    shootSound->setMedia(QUrl::fromLocalFile(constants::AudioFolder + "start.mp3"));
    shootSound->setVolume(40);
    shootSound->play();


    //shootSound->setMedia(QUrl("qrc:/sounds/1_audio/shoot_playermusic.mp3"));
    //shootSound->setMedia(QUrl("//Users//patrick//Downloads//img//1_audio//shoot_playermusic.mp3"));

    createObjects();
    createLayout();
    connectObjects();
}

void MainWidget::createObjects()
{
    //1. Create Objects

    titleLabel = new QLabel("<h1>Welcome Player ONE</h1>");
    titleLabel->setGeometry(0, 0, 10, 10);

    shootsLabel = new QLabel("#Shoots:");
    speedLabel = new QLabel("Speed:");
    angleLabel = new QLabel("Angle:");

    numberOfShotsInput = new QLineEdit();
    numberOfShotsInput->setReadOnly(true);

    speedInput = new QLineEdit();
    speedInput->setReadOnly(true);
    speedInput->setText("1");

    angleInput = new QLineEdit();
    angleInput->setReadOnly(true);
    angleInput->setText("0");

    actionButton = new QPushButton("Start");
    stop = new QPushButton("Stop");

    speedSlider = new QSlider(Qt::Horizontal);
    speedSlider->setMinimum(1);
    speedSlider->setMaximum(100);

    angleSlider = new QSlider(Qt::Horizontal);
    angleSlider->setMinimum(0);
    angleSlider->setMaximum(90);
}

void MainWidget::createLayout()
{
    //2. Create Layout
    QVBoxLayout *vAll = new QVBoxLayout();
    QVBoxLayout *vGameArea = new QVBoxLayout();
    QHBoxLayout *hBottom = new QHBoxLayout();

    //Adds the Backgroudimage and everything else from a gamearea object
    vAll->addWidget(titleLabel);

    vGameArea->addWidget(ga);

    //Das Widget ga bekommt am meisten Platz und andere schrumpfen zusammen so viel wie es geht
    ga->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    hBottom->addWidget(actionButton);
    hBottom->addWidget(stop);
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
    //Speedsilder
    QObject::connect(
                speedSlider, SIGNAL(valueChanged(int)),
                this, SLOT(speedSliderMoved(int)));

    //angleslider
    QObject::connect(
                angleSlider, SIGNAL(valueChanged(int)),
                this, SLOT(angleSliderMoved(int)));

    //actionbutton
    QObject::connect(
                actionButton, SIGNAL(clicked()),
                this, SLOT(actionButtonClicked()));

    //GameFinished
    QObject::connect(
                ga, SIGNAL(gameFinished()),
                this, SLOT(onGameFinished()));

    //Game Restart
    QObject::connect(
                this, SIGNAL(restartGame()),
                ga, SLOT(restarter()));

    actionReboot = new QAction( this );
    actionReboot->setText( tr("Restart") );
    actionReboot->setStatusTip( tr("Restarts the application") );
    QObject::connect( stop, SIGNAL(clicked()),this, SLOT (slotReboot()));

    /*
    Thread *t = new Thread(30);
    t->start();

    QObject::connect(, SIGNAL(refresh()),this, SLOT (slotReboot()));
*/
}

void MainWidget::onGameFinished()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Game Fnished", "Do you want to start a new game?",
                                    QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        resetGame();
        qDebug() << "Yes was clicked";
//      Restart Game
      } else {
        qDebug() << "Yes was *not* clicked";
        QApplication::quit();
      }
}

void MainWidget::slotReboot()
{
    //if(restart == true){
        qDebug() << "Performing application reboot...";
        restart = false;
        qApp->exit( MainWindow::EXIT_CODE_REBOOT);
    //}

}

void MainWidget::resetGame()
{
    init = true;
    numberOfShots = 0;
    emit restartGame();
    actionButton->setText("Start");
}

void MainWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_P){
        resetGame();
    }
    if(numberOfShots >= 0){
        if(event->key() == Qt::Key_W){
            ga->moven(2);
            //oben
        }
        if(event->key() == Qt::Key_S){
            ga->moven(1);
            //Unten
        }
    }
    if(event->key() == Qt::Key_Space){
        emit actionButtonClicked();
    }
    if(event->key() == Qt::Key_Q){
       //speed down
        if(speed >= 2){
            speed--;
            speedSlider->setValue(speed);
            QString s = QString::number(speed);
            speedInput->setText(s);
        }
    }
    if(event->key() == Qt::Key_E){
        if(speed <= 99){
            //speed up
            speed++;
            speedSlider->setValue(speed);
            QString s = QString::number(speed);
            speedInput->setText(s);
        }
    }
    if(event->key() == Qt::Key_A){
        if(angle >= 1){
            //angle down
            angle--;
            angleSlider->setValue(angle);
            QString s = QString::number(angle);
            angleInput->setText(s);
        }
    }
    if(event->key() == Qt::Key_D){
        if(angle <= 89){
            //angle up
            angle++;
            angleSlider->setValue(angle);
            QString s = QString::number(angle);
            angleInput->setText(s);
        }
    }
}
void MainWidget::speedSliderMoved(int value)
{
    //qDebug() << "SpeedSlider Value: " << value;

    speed = value;

    QString s = QString::number(speed);
    speedInput->setText(s);
}

void MainWidget::angleSliderMoved(int value)
{
    //qDebug() << "AngleSlider Value: " << value;

    angle = value;

    QString s = QString::number(angle);
    angleInput->setText(s);

}

void MainWidget::actionButtonClicked()
{
    //qDebug() << "actionButton clicked" << endl;


    if(init) {
        qDebug() << "MainWidget - start Game";
        init = false;
        actionButton->setText("Shoot");
        ga->startGame();
    } else {
        shootSound->play();
        ga->shoot(speed, angle);
        numberOfShots++;
        numberOfShotsInput->setText(QString::number(numberOfShots));
    }
}
