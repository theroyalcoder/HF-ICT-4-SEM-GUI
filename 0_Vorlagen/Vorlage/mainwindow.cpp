#include "mainwindow.h"

#include "widget.h"

#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    w = new Widget();
    setCentralWidget(w);
    this->statusBar()->showMessage("Connecting to server....", 4000);
}
