//
// Created by 张林星 on 2022/1/20.
//
#include <iostream>
#include "testrunnable.h"

namespace tbsys {
    TestRunnable::TestRunnable():CDefaultRunnable(3) {
        num = 5;
    }

    TestRunnable::~TestRunnable() {

    }
    void TestRunnable::run(CThread *thread, void *arg){
        int count = (int)((long)(arg));
        std::cout << "get count:"<< count<< std::endl;
    }
}
