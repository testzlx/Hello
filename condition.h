//
// Created by 张林星 on 2022/1/25.
//

#ifndef HELLOWORLD_CONDITION_H
#define HELLOWORLD_CONDITION_H
#include "noncopyable.h"
#include <pthread.h>
namespace muduo{
    class Condition: public noncopyable{
    public:
        Condition(){
            pthread_mutex_init(&_mutex, NULL);
            pthread_cond_init(&pcond_, NULL);
        }
        ~Condition()
        {
            pthread_cond_destroy(&pcond_);
            pthread_mutex_destroy(&_mutex);
        }
        void wait()
        {
            pthread_cond_wait(&pcond_, &_mutex);
        }


        void notify()
        {
            pthread_cond_signal(&pcond_);
        }

        void notifyAll()
        {
            pthread_cond_broadcast(&pcond_);
        }

    private:
        pthread_mutex_t  _mutex;
        pthread_cond_t pcond_;
    };
}
#endif //HELLOWORLD_CONDITION_H

