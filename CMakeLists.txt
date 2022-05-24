cmake_minimum_required(VERSION 3.9)
project(Hello)

set(CMAKE_CXX_STANDARD 11)

add_executable(Hello src/main/main.c src/include/bar.h src/include/foo.h src/foo/foo.c src/bar/bar.c)