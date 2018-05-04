#include "mainwindow.h"
#include "mainwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    int currentExitCode = 0;

    do{
        QApplication a(argc, argv);
        MainWindow w;
        w.setWindowTitle("QTG - Street Fighter Reloaded");
        w.show();
        //w.resize(QSize(900, 900));
        currentExitCode = a.exec();
    } while( currentExitCode == MainWindow::EXIT_CODE_REBOOT );

    return currentExitCode;

//    old -> lassen wegen Backup
    /*
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("QTG - Street Fighter Reloaded");
    w.show();
    //w.resize(QSize(900, 900));
    return a.exec();
    */
}
