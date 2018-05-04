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
#include <QAction>

MainWidget::MainWidget(QWidget *parent, int speed, int angle)
    : QWidget(parent), speed(0), angle(0), restart(false)
{
    ga = new GameArea(parent);
    init = true; // Init
    numberOfShots = 0;

//    Initialisation of shootSound
    bmgSound = new QMediaPlayer();
    bmgSound->setMedia(QUrl::fromLocalFile(constants::AudioFolder + "start.mp3"));
    bmgSound->setVolume(80);
    bmgSound->play();

//    sound pro Schuss => zu nervig / fällt in ein Limbus
//    shootSound = new QMediaPlayer();
//    shootSound->setMedia(QUrl::fromLocalFile(constants::AudioFolder + "shoot_playermusic.mp3"));
//    shootSound->setVolume(40);

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

    //Angleslider
    QObject::connect(
                angleSlider, SIGNAL(valueChanged(int)),
                this, SLOT(angleSliderMoved(int)));

    //Actionbutton
    QObject::connect(
                actionButton, SIGNAL(clicked()),
                this, SLOT(actionButtonClicked()));

    //Game Finished
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

    QObject::connect(
                stop, SIGNAL(clicked()),
                this, SLOT (slotReboot()));

//    Thread *t = new Thread(30);
//    t->start();
//    QObject::connect(, SIGNAL(refresh()),this, SLOT (slotReboot()));
}

void MainWidget::onGameFinished()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Game Finished", "Do you want to start a new game?",
                                    QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
//      Restart Game
        qDebug() << "Yes was clicked";
        resetGame();

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

//        Mit "EXIT_CODE_REBOOT" für Neustart
        qApp->exit(MainWindow::EXIT_CODE_REBOOT);
    //}
}

void MainWidget::resetGame()
{
    init = true; //Wichtig für Methode actionButtonClicked()
    numberOfShots = 0;
    bmgSound->stop();
    emit restartGame();
    actionButton->setText("Start");
}

void MainWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_P){
        resetGame();
    }

//    Eigenen Spieler bewegen
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

//    Schüsse abfeuern
    if(event->key() == Qt::Key_Space){
        emit actionButtonClicked();
    }

//    Geschwindigkeit anpassen
    if(event->key() == Qt::Key_Q){
       //speed down
        if(speed >= 2){
            speed-= 5;
            speedSlider->setValue(speed);
            QString s = QString::number(speed);
            speedInput->setText(s);
        }
    }
    if(event->key() == Qt::Key_E){
        if(speed <= 99){
            //speed up
            speed+= 5;
            speedSlider->setValue(speed);
            QString s = QString::number(speed);
            speedInput->setText(s);
        }
    }

//    Winkel anpassen
    if(event->key() == Qt::Key_A){
        if(angle >= 1){
            //angle down
            angle-= 5;
            angleSlider->setValue(angle);
            QString s = QString::number(angle);
            angleInput->setText(s);
        }
    }
    if(event->key() == Qt::Key_D){
        if(angle <= 89){
            //angle up
            angle+= 5;
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
        bmgSound->play();
        ga->shoot(speed, angle);
        numberOfShots++;
        numberOfShotsInput->setText(QString::number(numberOfShots));
    }
}
