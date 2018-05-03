#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "gamearea.h"
#include "gameobejct.h"

#include <QWidget>
#include <QSlider>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QInputDialog>
#include <QString>
#include <QtMultimedia/QSound>
#include <QMediaPlayer>
#include <QUrl>

class MainWidget : public QWidget
{
    Q_OBJECT
private:
    QString numberOfShots = "-1";
    int speed;
    int angle;
    bool restart;

    QMediaPlayer *shootSound;

    QSlider *angleSlider;
    QSlider *speedSlider;

    QPushButton *actionButton;
    QPushButton *stop;

    QLineEdit *numberOfShotsInput;
    QLineEdit *speedInput;
    QLineEdit *angleInput;

    QLabel *titleLabel;
    QLabel *shootsLabel;
    QLabel *speedLabel;
    QLabel *angleLabel;

    GameArea *ga;
    GameObject *obstacle;
    GameObject *player;
    GameObject *shoot;

    void createObjects();
    void createLayout();
    void connectObjects();

public:
    MainWidget(QWidget *parent = 0, int lspeed = 0, int langle = 0);
    void keyPressEvent(QKeyEvent *event);
    QAction *actionReboot;

public slots:
    void speedSliderMoved(int value);
    void angleSliderMoved(int value);
    void actionButtonClicked();
    void onGameFinished();
    void slotReboot();
};

#endif // MAINWIDGET_H
