#include "thread.h"

Thread::Thread() {

}

void Thread::run() {
    while (true) {
        emit doSomething();
        msleep(20);

    }

}
