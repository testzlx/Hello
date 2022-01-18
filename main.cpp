#include <iostream>
#include "stringutil.h"

using  namespace  tbsys;

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << CStringUtil::isInt("21")<<std::endl;
    char arr[]="abc";
    std::cout << CStringUtil::isInt(arr);
    return 0;
}
