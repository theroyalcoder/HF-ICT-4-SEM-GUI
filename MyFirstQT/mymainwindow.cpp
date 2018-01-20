#include "mymainwindow.h"
#include "ui_mymainwindow.h"
#include <QApplication>
#include <QPushButton>

MyMainWindow::MyMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyMainWindow)
{
    ui->setupUi(this);
}

MyMainWindow::~MyMainWindow()
{
    delete ui;
}
