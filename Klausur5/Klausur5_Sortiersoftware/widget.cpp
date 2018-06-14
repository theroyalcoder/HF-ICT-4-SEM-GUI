#include "widget.h"

#include <QAction>
#include <string>
#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QDebug>
#include <QSlider>
#include <QPaintEvent>
#include <QUrl>
#include <QMessageBox>
#include <QApplication>
#include <QTextEdit>
#include <algorithm>
#include <QListWidgetItem>


Widget::Widget(QWidget *parent): QWidget(parent)
{
    setWindowTitle(tr("Sortierungssoftware"));
    init();
    connects();
}

Widget::~Widget(){}

void Widget::connects(){

    QObject::connect(add,SIGNAL(clicked(bool)),this,SLOT(addClickedButton()));
    QObject::connect(clear,SIGNAL(clicked(bool)),this,SLOT(clearClickedButton()));
    QObject::connect(sort,SIGNAL(clicked(bool)),this,SLOT(sortClickedButton()));
    qDebug() << "connects";
}

void Widget::init(){

    area = new QTextEdit();
    edt = new QLineEdit();
    add = new QPushButton("Add");
    titel = new QLabel("<h1>Sortiersoftware<h1>");
    clear = new QPushButton("Clear");
    sort = new QPushButton("Sort");
    vAll = new QVBoxLayout();
    hBottom = new QHBoxLayout();

    vAll->addWidget(titel);
    vAll->addWidget(edt);
    hBottom->addWidget(add);
    hBottom->addWidget(clear);
    vAll->addLayout(hBottom);
    vAll->addWidget(area);
    vAll->addWidget(sort);

    setLayout(vAll);
    qDebug() << "init";

}

void Widget::sorting()
{

    std::sort (liste.begin(), liste.end());
    QString vector;

    for(auto a :liste){
        vector += QString::number(a) + "\n";
          qDebug() << a << endl;
    }

    area->setText(vector);
    qDebug() << "sorting" << endl;
}

void Widget::addClickedButton()
{
    QString s = edt->text();
    int value = s.toInt();
    liste.push_back(value);
    qDebug() << "adding : " << value;
}

void Widget::clearClickedButton()
{
    edt->setText("");
    liste.clear();
    qDebug() << "clearing";

}

void Widget::sortClickedButton()
{
    sorting();
}
