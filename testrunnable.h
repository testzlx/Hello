//
// Created by 张林星 on 2022/1/20.
//

#ifndef HELLOWORLD_TESTRUNNABLE_H
#define HELLOWORLD_TESTRUNNABLE_H
#include "defaultrunnable.h"
namespace tbsys {
    class TestRunnable : public CDefaultRunnable{
        public:
            TestRunnable();
            ~TestRunnable();

            void run(CThread *thread, void *arg);

        private:
            int num;

    };
}
#endif //HELLOWORLD_TESTRUNNABLE_H
