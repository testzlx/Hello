//
// Created by 张林星 on 2022/1/20.
//

#ifndef HELLOWORLD_RUNNABLE_H
#define HELLOWORLD_RUNNABLE_H

#include "thread.h"

namespace tbsys {

    class CThread;

/**
 * @brief Runnable是一个抽象类，它拥有一个run纯虚方法
 * 主要用于Thread类
 */
    class Runnable {

    public:
        /*
         * 析构
         */
        virtual ~Runnable() {
        }

        /**
         * 运行入口函数
         */
        virtual void run(CThread *thread, void *arg) = 0;
    };

}
#endif //HELLOWORLD_RUNNABLE_H
