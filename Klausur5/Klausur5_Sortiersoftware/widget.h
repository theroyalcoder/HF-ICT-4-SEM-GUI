#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QListWidget>
#include <vector>
#include <QAction>
#include <string>
#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QDebug>
#include <QSlider>
#include <QPaintEvent>
#include <QUrl>
#include <QMessageBox>
#include <QApplication>
#include <QTextEdit>

class Widget : public QWidget
{
    Q_OBJECT

private:
    QListWidget *list = new QListWidget;
    std::vector<int> liste;

    QTextEdit *area;
    QLineEdit *edt;
    QPushButton *add;
    QLabel *titel;
    QPushButton *clear;
    QPushButton *sort;
    QVBoxLayout *vAll;
    QHBoxLayout *hBottom;

public:

    Widget(QWidget *parent = 0);
    ~Widget();
    void init();
    void connects();
    void sorting();

public slots:

    void addClickedButton();
    void clearClickedButton();
    void sortClickedButton();

};

#endif // WIDGET_H
