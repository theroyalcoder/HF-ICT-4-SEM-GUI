#ifndef PAINTAREA_H
#define PAINTAREA_H

#include <QWidget>

class QPaintEvent;

class PaintArea : public QWidget
{
    Q_OBJECT
public:
    explicit PaintArea(QWidget *parent = 0);
    void setNumberOfPoints(int numberOfPoints);
    void paintEvent(QPaintEvent *event);
    void setResetFlag(bool value);
    double getResult() const;

private:
    int numberOfPoints;
    bool reset;
    double result;

public slots:

signals:
};

#endif // PAINTAREA_H
