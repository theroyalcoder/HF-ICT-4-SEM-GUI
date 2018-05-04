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

//https://wiki.qt.io/How_to_make_an_Application_restartable/de
int const MainWindow::EXIT_CODE_REBOOT = -123456789;

MainWindow::~MainWindow() {}
