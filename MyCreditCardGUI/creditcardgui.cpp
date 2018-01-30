#include "creditcardgui.h"
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QPushButton>
#include <QComboBox>

CreditCardGUI::CreditCardGUI()
{
    //Titel
    QLabel *lbl_title = new QLabel("<h1> Credit Card Checker </h1>");

    //Zahlen eingeben
    QLabel *lbl_num = new QLabel("Nr.: ");
    QLineEdit *le_num1 = new QLineEdit();
    QLineEdit *le_num2 = new QLineEdit();
    QLineEdit *le_num3 = new QLineEdit();
    QLineEdit *le_num4 = new QLineEdit();

    //Ablaufdatum
    QLabel *lbl_ablaufdatum = new QLabel("Ablaufdatum: ");
    //todo: Dropdown machen
    QComboBox *cb_month = new QComboBox();
    cb_month->addItem("Januar");
    cb_month->addItem("Febraur");
    cb_month->addItem("März");
    cb_month->addItem("April");
    cb_month->addItem("Mai");
    cb_month->addItem("Juni");
    cb_month->addItem("Juli");
    cb_month->addItem("August");
    cb_month->addItem("September");
    cb_month->addItem("Oktober");
    cb_month->addItem("November");
    cb_month->addItem("Dezember");

    QComboBox *cb_year = new QComboBox();
    cb_year->addItem("2017");
    cb_year->addItem("2018");
    cb_year->addItem("2019");
    cb_year->addItem("2020");
    cb_year->addItem("2021");
    cb_year->addItem("2022");
    cb_year->addItem("2023");
    cb_year->addItem("2024");
    cb_year->addItem("2025");
    cb_year->addItem("2026");
    cb_year->addItem("2027");
    cb_year->addItem("2028");
    cb_year->addItem("2029");
    cb_year->addItem("2030");

    //OK Button -> Msg Box machen
    QPushButton *bt_ok = new QPushButton("OK");
    bt_ok->setToolTip("TEXT XYZ");

    //Status -> Chng Evt Handling machen
        //Status "Gültig" oder "Nicht Gültig"
    QLabel *lbl_status = new QLabel("Status: ");



    //Hauptlayout
    QWidget *widget = new QWidget();
    QVBoxLayout *vLayout = new QVBoxLayout();

    //Titel
    vLayout->addWidget(lbl_title);

    //Nr.
    QHBoxLayout *hLayout1 = new QHBoxLayout();
    hLayout1->addWidget(lbl_num);
    hLayout1->addWidget(le_num1);
    hLayout1->addWidget(le_num2);
    hLayout1->addWidget(le_num3);
    hLayout1->addWidget(le_num4);

    //Ablaufdatum
    QHBoxLayout *hLayout2 = new QHBoxLayout();
    hLayout2->addWidget(lbl_ablaufdatum);
    hLayout2->addWidget(cb_month);
    hLayout2->addWidget(cb_year);

    //OK Button
    QHBoxLayout *hLayout3 = new QHBoxLayout();
    hLayout3->addWidget(bt_ok);

    //Status
    QHBoxLayout *hLayout4 = new QHBoxLayout();
    hLayout4->addWidget(lbl_status);


    //hLayouts ins vLayout hinzufügen
    vLayout->addItem(hLayout1);
    vLayout->addItem(hLayout2);
    vLayout->addItem(hLayout3);
    vLayout->addItem(hLayout4);

    widget->setLayout(vLayout);
    widget->show();



}
