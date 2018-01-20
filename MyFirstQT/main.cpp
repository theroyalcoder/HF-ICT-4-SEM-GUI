#include "mymainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QDial>
#include <QSlider>
#include <QLCDNumber>
#include <QDebug>
#include <QCloseEvent>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    //MyMainWindow w;
    //w.show();

    QPushButton *button1 = new QPushButton("Push Me 1");
    QPushButton *button2 = new QPushButton("Push Me 2");
    QLineEdit *textfield = new QLineEdit;
    QWidget *widget = new QWidget();
    QHBoxLayout * hlayout = new QHBoxLayout();
    hlayout->addWidget(button1);
    hlayout->addWidget(button2);
    hlayout->addWidget(textfield);
    widget->setLayout(hlayout);
    widget->show();



    //QCloseEvent *button2 = new QCloseEvent();
    //button2->Close();

    /*
    QDial *dial = new QDial();
    dial->show();

    QSlider *slider = new QSlider();
    slider->show();

    QLCDNumber *lcdnumber = new QLCDNumber();
    lcdnumber->display(1234);
    lcdnumber->show();

    qDebug() << "sfasjflas";
    //qWarning() << "warnin";
    */

    return a.exec();
}
