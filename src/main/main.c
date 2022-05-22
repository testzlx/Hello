//
// Created by zhanglinxing on 2021/6/30.
//
#include <stdio.h>
#include "../include/foo.h"
#include "../include/bar.h"
int main(int argc, char *argv[])
{
    printf("main +\n");
    func_foo();
    func_bar();
    printf("main -\n");
    return 0;
}
