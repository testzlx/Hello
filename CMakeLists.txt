cmake_minimum_required(VERSION 3.17)
project(helloworld)

set(CMAKE_CXX_STANDARD 14)

add_executable(helloworld main.cpp stringutil.h stringutil.cpp runnable.h thread.h testrunnable.h testrunnable.cpp thread.cpp defaultrunnable.h defaultrunnable.cpp)