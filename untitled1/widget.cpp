#include "widget.h"

#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // 1. Create Objects
    QLabel *title = new QLabel("<h1>Das ist ein TITEL</h1>");
    QLabel *text = new QLabel("text fljdslfjas");
    QPushButton *okButton = new QPushButton("OK");
    QLineEdit *inputLine = new QLineEdit();

    // 2. Create Layout
    //Wichtig ist darauf zu achten, ob man ein hBox oder vBox (horizontal oder vertikal) nimmt
    QVBoxLayout *vBox = new QVBoxLayout();
    QHBoxLayout *hBox = new QHBoxLayout();
    vBox->addWidget(title);
    hBox->addWidget(text);
    hBox->addWidget(inputLine);
    vBox->addLayout(hBox);
    vBox->addWidget(okButton);

    // 3. Set Main Layout
    setLayout(vBox);
}
Widget::~Widget()
{

}
