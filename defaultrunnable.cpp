//
// Created by 张林星 on 2022/1/20.
//
#include "defaultrunnable.h"

namespace tbsys {

/**
 * 构造
 */
    CDefaultRunnable::CDefaultRunnable(int threadCount) {
        _stop = false;
        _threadCount = threadCount;
        _thread = NULL;
    }

/*
 * 析构
 */
    CDefaultRunnable::~CDefaultRunnable() {
        if (_thread) {
            delete[] _thread;
            _thread = NULL;
        }
    }

/**
 * 设置线程数
 */
    void CDefaultRunnable::setThreadCount(int threadCount) {
        if (_thread != NULL) {
            return;
        }
        _threadCount = threadCount;
    }

// start
    int CDefaultRunnable::start() {
        if (_thread != NULL || _threadCount < 1) {
            return 0;
        }
        _thread = new CThread[_threadCount];
        if (NULL == _thread) {
            return 0;
        }
        int i = 0;
        for (; i < _threadCount; i++) {
            if (!_thread[i].start(this, (void *) ((long) i))) {
                return i;
            }
        }
        return i;
    }

// stop
    void CDefaultRunnable::stop() {
        _stop = true;
    }

// wait
    void CDefaultRunnable::wait() {
        if (_thread != NULL) {
            for (int i = 0; i < _threadCount; i++) {
                _thread[i].join();
            }
        }
    }

}
