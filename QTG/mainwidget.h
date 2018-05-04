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
    int numberOfShots;
    int speed;
    int angle;
    bool restart;

    QMediaPlayer *bmgSound;

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

    bool init; // For init
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
    void resetGame();

signals:
    void restartGame();
};

#endif // MAINWIDGET_H
