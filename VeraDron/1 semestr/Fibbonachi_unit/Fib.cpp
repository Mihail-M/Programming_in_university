#include "fib.h"
#define DEBUG 0
#include <iostream>

long long fib(int n){
    int f1 = 1;
    int f2 = 1;
    int f3 = 0;
    #if DEBUG
    std::cout << "1 - 1 -";
    #endif
    for (int i = 2; i < n; i++) {
        f3 = f1 + f2;
        #if DEBUG
        std::cout << f3 << " - ";
        #endif
        f1 = f2;
        f2 = f3;
    }
    #if DEBUG
    std::cout << " \n";
    #endif
    return f2;
}

