//
// Created by 张林星 on 2022/1/20.
//

#ifndef HELLOWORLD_THREAD_H
#define HELLOWORLD_THREAD_H
#include "runnable.h"
#include <thread>

namespace tbsys {

    class Runnable;
/**
 * @brief 对linux线程简单封装
 */
class CThread {

    public:
        /**
         * 构造函数
         */
        CThread() {
            tid = 0;
            pid = 0;
        }

        /**
         * 起一个线程，开始运行
         */
        bool start(Runnable *r, void *a) {
            runnable = r;
            args = a;
            return 0 == pthread_create(&tid, NULL, CThread::hook, this);
        }

        /**
         * 等待线程退出
         */
        void join() {
            if (tid) {
                pthread_join(tid, NULL);
                tid = 0;
                pid = 0;
            }
        }

        /**
         * 得到Runnable对象
         *
         * @return Runnable
         */
        Runnable *getRunnable() {
            return runnable;
        }

        /**
         * 得到回调参数
         *
         * @return args
         */
        void *getArgs() {
            return args;
        }

        /***
         * 得到线程的进程ID
         */
        int getpid() {
            return pid;
        }

        /**
         * 线程的回调函数
         *
         */

        static void *hook(void *arg);

    private:
        pthread_t tid;      // pthread_self() id
        int pid;            // 线程的进程ID
        Runnable *runnable;
        void *args;
    };

}
#endif //HELLOWORLD_THREAD_H
