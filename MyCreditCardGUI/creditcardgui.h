#ifndef CREDITCARDGUI_H
#define CREDITCARDGUI_H
#include <QApplication>
#include <QWidget>

class QComboBox;
class QLineEdit;

class CreditCardGUI
{
public:
    CreditCardGUI();
    QString getBlock1();

private:
    void init();

    QComboBox *monthBox;
    QComboBox *yearBox;

    QLineEdit *block1Input;
    QLineEdit *block2Input;
    QLineEdit *block3Input;
    QLineEdit *block4Input;
};

#endif // CREDITCARDGUI_H
