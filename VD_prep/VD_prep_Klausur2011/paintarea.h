#ifndef PAINTAREA_H
#define PAINTAREA_H

#include <QWidget>
#include <iostream>
#include <vector>
using namespace std;

class QPaintEvent;

class PaintArea : public QWidget
{
    Q_OBJECT
public:
    explicit PaintArea(QWidget *parent = 0);
    void setNumberOfPoints(int numberOfPoints);
    void paintEvent(QPaintEvent *event);
    void setResetFlag(bool value);
    double getResult();
    void setResult(double value);

private:
    int numberOfPoints;
    bool reset;
    double result;
    vector<int> PointPosX;
    vector<int> PointPosY;
    double xCirclePos, yCirclePos;
    double xCircleSize = 50.0;
    double yCircleSize = 50.0;

};

#endif // PAINTAREA_H
