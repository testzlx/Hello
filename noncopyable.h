//
// Created by 张林星 on 2022/1/25.
//

#ifndef HELLOWORLD_NONCOPYABLE_H
#define HELLOWORLD_NONCOPYABLE_H
namespace muduo{

    class noncopyable{
    protected:
        noncopyable() =default;
        ~noncopyable() =default;
    public:
        noncopyable(const noncopyable&) = delete;
        void operator=(const noncopyable&) =delete;
    };
}
#endif //HELLOWORLD_NONCOPYABLE_H
