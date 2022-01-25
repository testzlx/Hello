//
// Created by 张林星 on 2022/1/20.
//

#ifndef HELLOWORLD_THREADMUTEX_H
#define HELLOWORLD_THREADMUTEX_H
#include "pthread.h"
#include <assert.h>

class CThreadMutex {
public:
    CThreadMutex(){
        const  int iRet = pthread_mutex_init(&_mutex, nullptr);
        assert(iRet == 0);
    }

    ~CThreadMutex(){
        pthread_mutex_destroy(&_mutex);
    }
    void lock(){
        pthread_mutex_lock(&_mutex);
    }

    int trylock(){
        return pthread_mutex_trylock(&_mutex);
    }

    void unlock(){
        pthread_mutex_unlock(&_mutex);
    }

private:
    pthread_mutex_t  _mutex;

};

class CThreadGuard{
public:
    CThreadGuard(CThreadMutex *mutex){
        _mutex = nullptr;
        if(mutex) {
            _mutex = mutex;
            _mutex->lock();
        }
    }
    ~CThreadGuard(){
        if(_mutex){
            _mutex->unlock();
        }
    }
private:
    CThreadMutex *_mutex;
};
#endif //HELLOWORLD_THREADMUTEX_H
