#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

class MyWidget : public QWidget {

    Q_OBJECT

public slots:
    void onButtonClicked();
private:
    QLabel *titleLabel = new QLabel();
    QLabel *textLabel = new QLabel();
    QPushButton *okButton = new QPushButton();
    QLineEdit *inputLineEdit = new QLineEdit();
public:
    MyWidget();
};

#endif // MYWIDGET_H
