#include "thread.h"

#include <QThread>

Thread::Thread() :running(true) {}

void Thread::stopThread()
{
  running = false;
}

void Thread::run()
{
    while(running) {
        emit refresh();
        msleep(50);
    }
}
