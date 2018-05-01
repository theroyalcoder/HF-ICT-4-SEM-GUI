#include "thread.h"

#include <QThread>

Thread::Thread(int nspeed)
{
speed = nspeed;
}

void Thread::run()
{
    while(true) {
        emit refresh();
        msleep(speed);
    }
}
