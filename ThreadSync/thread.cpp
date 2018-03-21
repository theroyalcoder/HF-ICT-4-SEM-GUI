#include "thread.h"

#include <QDebug>
#include <cstdlib>
#include <ctime>
#include <QMutex>
#include <QMutexLocker>
#include <QWaitCondition>

Datacontainer::Datacontainer() : dataAvailable(false) {
    //QMutex: Ablauf erzwingen
    mutex = new QMutex();

    //QWaitcondition: Thread in verschiedene Zustände setzen (wait, run, usw.)
    waitCon = new QWaitCondition();
}

void Datacontainer::setValue(int value) {
    //QMutexLocker: Niemand darf diese Methode unterbrechen
    QMutexLocker locker(mutex);

    //Solange dataAvailable true ist, soll es warten
    while(dataAvailable) {
        waitCon->wait(mutex);
    }

    this->value = value;
    dataAvailable = true;
    waitCon->wakeAll();
}

int Datacontainer::getValue() {
    QMutexLocker locker(mutex);

    while(!dataAvailable) {
        waitCon->wait(mutex);
    }
    dataAvailable = false;
    waitCon->wakeAll();

    return value;
}

//Den ID Generator auf 0 setzen
int Writer::idGenerator = 0;

Writer::Writer(Datacontainer *c) : con(c), running(true) {
    id = idGenerator;
    ++idGenerator;
}

void Writer::run() {
    srand(time(NULL));

    while(running) {
        int val = rand() % 1000 + 1;
        con->setValue(val);
        qDebug() << "ID: " << id << "Write: " << val;
        msleep(200);
    }
}

void Writer::stopThread() {
    running = false;
}

int Reader::idGenerator = 1000;

Reader::Reader(Datacontainer *c) : con(c), running(true) {
    id = idGenerator;
    idGenerator++;
}

void Reader::run() {
    srand(time(NULL));

    while (running) {
        int val = con->getValue();
        qDebug() << "ID: " << id << "Read: " << val;
        msleep(rand() % 2000);
    }
}

void Reader::stopThread() {
    running = false;
}
