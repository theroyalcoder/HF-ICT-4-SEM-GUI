#include "creditcardgui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CreditCardGUI *CCGUI = new CreditCardGUI();


    return a.exec();
}
