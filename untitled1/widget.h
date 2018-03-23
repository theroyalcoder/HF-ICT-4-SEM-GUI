#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

class Widget : public QWidget
{
    Q_OBJECT
private:
    QLabel *title;
    QLabel *text;

    QLineEdit *inputLine2;
    QPushButton *okButton;
    QPushButton *okButton2;

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    QLineEdit *inputLine;
    QLineEdit *getInputLine() const;
};

#endif // WIDGET_H
