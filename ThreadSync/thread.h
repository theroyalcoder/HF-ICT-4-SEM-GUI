#ifndef THREAD_H
#define THREAD_H

#include <QThread>


class QMutex;
class QWaitCondition;

class Datacontainer {
private:
    int value;
    bool dataAvailable;
    QMutex *mutex;
    QWaitCondition *waitCon;
public:
    Datacontainer();
    void setValue(int value);
    int getValue();

};

class Writer : public QThread {
private:
    Datacontainer *con;
    bool running;
    int id;
    static int idGenerator;
public:
    Writer(Datacontainer *c);
    void run();
    void stopThread();
};

class Reader : public QThread {
private:
    Datacontainer *con;
    bool running;
    int id;
    static int idGenerator;
public:
    Reader(Datacontainer *c);
    void run();
    void stopThread();
};

#endif // THREAD_H
