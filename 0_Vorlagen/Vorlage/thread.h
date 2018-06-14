#ifndef THREAD_H
#define THREAD_H

#include <QThread>

class Thread : public QThread
{
    Q_OBJECT
public:
    Thread();
    void stopThread();
    void run();
private:
    bool running;
signals:
    void refresh();
};

#endif // THREAD_H
