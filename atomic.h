//
// Created by 张林星 on 2022/1/25.
//

#ifndef HELLOWORLD_ATOMIC_H
#define HELLOWORLD_ATOMIC_H
#include "noncopyable.h"
namespace muduo{
    template <typename  T>
class AtomicInteger: public noncopyable{
public:
    AtomicInteger():value_(0){

    }
    T get(){
        return __sync_val_compare_and_swap(&value_,0,0);
    }

    T getAndAdd(T x){
        return __sync_fetch_and_add(&value_,x);
    }
    T addAndGet(T x)
    {
        return getAndAdd(x) + x;
    }

    T incrementAndGet()
    {
        return addAndGet(1);
    }

    T decrementAndGet()
    {
        return addAndGet(-1);
    }

    void add(T x)
    {
        getAndAdd(x);
    }

    void increment()
    {
        incrementAndGet();
    }

    void decrement()
    {
        decrementAndGet();
    }

    T getAndSet(T newValue)
    {
        // in gcc >= 4.7: __atomic_exchange_n(&value_, newValue, __ATOMIC_SEQ_CST)
        return __sync_lock_test_and_set(&value_, newValue);
    }
private:
    volatile T value_;
};
}
#endif //HELLOWORLD_ATOMIC_H
