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
    QLabel titleLabel();
    QLabel textLabel();
    QPushButton okButton();
    QLineEdit inputLineEdit();
public:
    MyWidget();
};

#endif // MYWIDGET_H
