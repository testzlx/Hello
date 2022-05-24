//
// Created by 张林星 on 2022/1/20.
//

#ifndef HELLOWORLD_DEFAULTRUNNABLE_H
#define HELLOWORLD_DEFAULTRUNNABLE_H
#include "runnable.h"
#include "thread.h"
namespace tbsys {

/**
 * @brief 线程执行具体的业务的封装类,同时它维护了一个线程数据，也可以将此类
 * 看成一个线程池类
 */
    class CDefaultRunnable : public Runnable {

    public:
        /**
         * 构造
         */
        CDefaultRunnable(int threadCount = 1);

        /**
         * 析构
         */
        virtual ~CDefaultRunnable();

        /**
         * 设置线程数
         */
        void setThreadCount(int threadCount);

        /**
         * create %_threadCount threads
         * @return started thread count;
         */
        int start();

        /**
         * stop
         */
        void stop();

        /**
         * wait
         */
        void wait();

    protected:
        CThread *_thread;
        int _threadCount;
        bool _stop;
    };

}
#endif //HELLOWORLD_DEFAULTRUNNABLE_H
