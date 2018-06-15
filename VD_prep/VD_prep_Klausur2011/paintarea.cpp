#include "paintarea.h"

#include <QPainter>
#include <QDebug>
#include <stdlib.h>
#include <time.h>
#include <cmath>

PaintArea::PaintArea(QWidget *parent) : QWidget(parent)
{
//    qDebug() << "PaintArea Konstruktur";
}

void PaintArea::setNumberOfPoints(int numberOfPoints)
{
    this->numberOfPoints = numberOfPoints;
}

void PaintArea::paintEvent(QPaintEvent *event)
{
//    qDebug() << "PaintEvent";
    QPainter painter(this);

    if(reset)
        return;

    srand(static_cast<unsigned int>(time(nullptr)));

    xCirclePos = rand() % 450;
    yCirclePos = rand() % 450;

    //Kreis
    QRectF rectangle(xCirclePos, yCirclePos, xCircleSize, yCircleSize);
    painter.drawEllipse(rectangle);

    //Points
    QPen linepen(Qt::red);
    linepen.setCapStyle(Qt::RoundCap);
    linepen.setWidth(2);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setPen(linepen);

    //Generiere zufaellige shooting punkte und speichere diese in ein array zum resultat herausfinden
    double x = rand() % 450;
    double y = rand() % 450;

    for(int i= 0; i < numberOfPoints -1; i++){
        x = rand() % 450;
        y = rand() % 450;

        PointPosX.push_back(x);
        PointPosY.push_back(y);

        QPoint pos(x, y);
        painter.drawPoint(pos);
    }

}

void PaintArea::setResetFlag(bool value)
{
    reset = value;
}

void PaintArea::setResult(double value)
{
    result = value;
}

double PaintArea::getResult()
{
    int delta = 0;
    this->setResult(0);
    int cal1 = 0;
    int cal2 = 0;
    double res = 0;

    for(auto x : PointPosX){
        qDebug() << "PointposX: " << x;
    }


    for(int i= 0; i < numberOfPoints -1; i++){

//        cal1 = (xCirclePos - arr[i])     + (xCirclePos - arr[i]);
//        cal2 = (yCirclePos - arr[i + 1]) + (yCirclePos - arr[i + 1]);

//        delta = sqrt(cal1 + cal2);

        if(delta >= 50){
            res++;
        }
    }

//    this->setResult(res);

    return result;
}
