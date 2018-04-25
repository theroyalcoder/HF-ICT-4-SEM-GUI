#include "mainwindow.h"
#include "mainwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    MainWidget *mw = new MainWidget;
    this->setCentralWidget(mw);
    //mw->setWindowTitle("QTG");
    this->setFixedSize(1000, 650);
}

MainWindow::~MainWindow()
{

}
