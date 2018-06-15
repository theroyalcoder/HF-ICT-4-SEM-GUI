#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include <cmath>
#include <QMessageBox>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    createObjects();
    createLayout();
    connectObjects();

    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::createObjects()
{
    //1. Create Objects
    titel = new QLabel("<h1>Prime Checker</h1>");
    titel->setGeometry(0, 0, 10, 10);

    eingabe = new QLineEdit(this);
    //Validiert: So kann man Werte zwischen 0 - 100 eingeben
    //eingabe->setValidator( new QIntValidator(0, 100, this));

    check = new QPushButton("check");
}

void Widget::createLayout()
{
    //2. Create Layout
    QVBoxLayout *vAll = new QVBoxLayout();
    QHBoxLayout *hBottom = new QHBoxLayout();
    QHBoxLayout *hBottom2 = new QHBoxLayout();

    vAll->addWidget(titel);
    hBottom->addWidget(eingabe);
    hBottom2->addWidget(check);

    vAll->addLayout(hBottom);
    vAll->addLayout(hBottom2);

    //3. Set Main Layout
    this->setLayout(vAll);
}

void Widget::connectObjects()
{
    QObject::connect(
                check, SIGNAL(clicked()),
                this, SLOT(checkButtonClicked()));
}

void Widget::checkButtonClicked()
{
    qDebug() << "checkButton clicked" << endl;

    int i;
    bool isPrime = true;
    QString debugMessage = "";
    QMessageBox::StandardButton result;
    int value = 0;

    //Ueberpruefen, ob Wert eine Zahl ist
    if(eingabe->text().toInt()) {
        //Ja
        value = eingabe->text().toInt();

        for(i = 2; i <= value / 2; ++i)
        {
            if(value % i == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            debugMessage = "This is a prime number";
            qDebug() << debugMessage;
        } else {
            debugMessage = "This is NOT a prime number";
            qDebug() << debugMessage;
        }

        result = QMessageBox::information(this, "TITEL", debugMessage, QMessageBox::Ok);
    } else {
        //Nein
        result = QMessageBox::critical(this, "TITEL", "This is not a number", QMessageBox::Ok);

    }


}
