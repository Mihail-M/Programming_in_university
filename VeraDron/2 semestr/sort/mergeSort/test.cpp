#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include "test.h"

bool is_ok(int *a, int *b, int n)
{
    for (int i = 0; i < n; i++)
        if(a[i] != b[i])
            return false;
    return true;
}

void test(void (*sortArray)(int*, int, int))
{
    for(int i = 1; i <= 7; i++)
    {
        std::string path = "test/test";
        path += i +'0';
        path += ".txt";
        std::ifstream in;
        in.open(path.c_str());
        int k = 0;
        in >> k;
        int *a = new int[k];
        int *ans = new int[k];

        for (int i = 0; i < k; i++)
        {
            in >> a[i];
            ans[i] = a[i];
        }

        std::sort(ans, ans + k);
        (*sortArray)(a, 0 , k-1);


        if(is_ok(a, ans, k))
            std::cout << path + " is ok!" << std::endl;
        else std::cout << "nine" << std::endl;

        in.close();
        delete[] a;
        delete[] ans;
    }
}
