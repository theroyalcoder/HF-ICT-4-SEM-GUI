#include "mywidget.h"
#include <QObject>

MyWidget::MyWidget() {
    titleLabel->setText("TITEL");
    textLabel->setText("TEXT");
    okButton->setText("OK");


   // QObject::connect(okButton, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
}


void MyWidget::onButtonClicked() {
    // delete the content of the QLineEdit component
    //inputLineEdit().clear();
}
