#ifndef THREAD_H
#define THREAD_H

#include <QThread>

class Thread : public QThread
{
    Q_OBJECT
public:
    Thread(int nspeed);
    void run();
private:
    int speed;
signals:
    void refresh();
};

#endif // THREAD_H
