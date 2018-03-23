#include "widget.h"
#include "eventhandler.h"

#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QIntValidator>
#include <QString>
#include <QPalette>

QLineEdit *Widget::getInputLine() const
{
    return inputLine;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // 1. Create Objects
    title = new QLabel("<h1>Das ist ein TITEL</h1>");
    text = new QLabel("text fljdslfjas");
    inputLine2 = new QLineEdit();
    inputLine = new QLineEdit();
    okButton = new QPushButton("OK");

    //Eventhandling (s. S 32)
    Eventhandler *e = new Eventhandler(this);
    QObject::connect(okButton, SIGNAL (clicked()),
                     e, SLOT(onButtonClicked()) );


    //Change Background of Color of QLineEdit
    QPalette p = inputLine->palette();
    p.setColor(QPalette::Normal, QPalette::Base, Qt::lightGray);
    inputLine->setPalette(p);

    //Validate Input
    //Methode 1: Using a validator
    QIntValidator *val = new QIntValidator();
    val->setRange(1, 9);
    inputLine->setValidator(val);

    //Methode 2: Check the values after commit (funktioniert nicht)
    /*
    bool convertSuccessful;
    int value = inputLine2->text().toInt(convertSuccessful);
    if (*convertSuccessful) {
        qDebug << "Convert successful: " << value;
    } else {
        qDebug << "Convert NOT successful: " << value;
    }
    */

    // 2. Create Layout
    //Wichtig ist darauf zu achten, ob man ein hBox oder vBox (horizontal oder vertikal) nimmt
    QVBoxLayout *vBox = new QVBoxLayout();
    QHBoxLayout *hBox = new QHBoxLayout();
    vBox->addWidget(title);
    hBox->addWidget(text);
    hBox->addWidget(inputLine);
    hBox->addWidget(inputLine2);
    vBox->addLayout(hBox);
    vBox->addWidget(okButton);

    // 3. Set Main Layout
    setLayout(vBox);
}

Widget::~Widget()
{

}
