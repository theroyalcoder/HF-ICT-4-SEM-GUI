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

class MainWidget : public QWidget
{
    Q_OBJECT
private:
    QString numberOfShots = "-1";

    QSlider *angleSlider;
    QSlider *speedSlider;

    QPushButton *actionButton;

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
    MainWidget(QWidget *parent = 0);
    void speedSliderMoved(int value);
    void angleSliderMoved(int value);
    void actionButtonClicked();
    void onGameFinished();

public slots:
    void setSpeedInputValue(int v);
    void setAngleInputValue(int v);
    void setActionButtonValue();
};

#endif // MAINWIDGET_H
