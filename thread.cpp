//
// Created by 张林星 on 2022/1/20.
//
#include "thread.h"

namespace tbsys {
    void* CThread::hook(void *arg) {
        CThread *thread = (CThread*) arg;
        thread->pid = 19384;

        if (thread->getRunnable()) {
            thread->getRunnable()->run(thread, thread->getArgs());
        }

        return (void*) NULL;
    }
}
