#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QLabel *titel;
    QLineEdit *eingabe;
    QPushButton *check;

    void createObjects();
    void createLayout();
    void connectObjects();
private:
    Ui::Widget *ui;

public slots:
    void checkButtonClicked();

};

#endif // WIDGET_H
