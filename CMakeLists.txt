cmake_minimum_required(VERSION 3.17)
project(helloworld)

set(CMAKE_CXX_STANDARD 14)

add_executable(helloworld main.cpp stringutil.h stringutil.cpp runnable.h thread.h thread.cpp testrunnable.h testrunnable.cpp defaultrunnable.h defaultrunnable.cpp threadmutex.h noncopyable.h atomic.h condition.h bytebuffer.h)