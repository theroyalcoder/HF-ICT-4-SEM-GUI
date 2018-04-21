#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QSlider>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QInputDialog>

class MainWidget : public QWidget
{
    Q_OBJECT
private:
    QSlider *angleSlider;
    QSlider *speedSlider;
    QPushButton *actionButton;
    QLineEdit *numberOfShotsInput;
    QLineEdit *speedInput;
    QLabel *titleLabel;
    QLabel *shootsLabel;
    QInputDialog *in_shoots;
    QInputDialog *in_speed;
    QInputDialog *in_angle;
    void createObjects();
    void createLayout();
    void connectObjects();
public:
    MainWidget(QWidget *parent = 0);
    void speedSliderMoved(int );
    void angleSliderMoved(int );
    void actionButtonClicked(int );
    void onGameFinished();
};

#endif // MAINWIDGET_H
