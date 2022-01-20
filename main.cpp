#include <iostream>
#include "stringutil.h"
#include "testrunnable.h"

using  namespace  tbsys;
using  namespace  std;

void testStringUtil(){
    std::cout << CStringUtil::isInt("21")<<endl;
    char arr[]="ABC##BCD#G";
    std::cout << CStringUtil::isInt(arr)<<endl;
    std::cout << CStringUtil::strToLower(arr)<<endl;
    vector<char*> result;
    CStringUtil::split(arr,"#",result);
    for (int i = 0;i < result.size();i++) {
        cout << result[i] << endl;
    }
}

void testThread(){
    TestRunnable testRunnable;
    CThread cThread;
    cThread.start(&testRunnable, (void *)99);
    cThread.join();
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    testStringUtil();
    testThread();
    return 0;
}
