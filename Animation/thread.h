#ifndef THREAD_H
#define THREAD_H

#include <QThread>

class Widget;

class Thread : public QThread {
        Q_OBJECT
private:

public:
    Thread();
    void run();

signals:
    void doSomething();
};

#endif // THREAD_H
