#include <QCoreApplication>
#include <
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    hint hi1;

    hi1.print();

    return a.exec();
}
