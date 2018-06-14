#ifndef GUI_H
#define GUI_H
#include "PaintArea.h"

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QPaintEvent>

class QPaintEvent;


class Gui : public QWidget
{
    Q_OBJECT
public:
    Gui();
    //explicit Gui(QWidget *parent = 0);
    ~Gui();

private:
    QLineEdit *numberInput;
    QPushButton *goButton;
    QPushButton *resetButton;
    PaintArea *paintArea;
    QLabel *resultLabel;

public slots:
    void onGoButtonPressed();
    void onResetButtonPressed();

};

#endif // GUI_H
