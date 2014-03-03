#include <iostream>
#include "queue.h"
using namespace std;

int main()
{
    Queue a;
    for(int i = 0; i < 1000; i++)
        a.push(i);
    for(int i = 0; i < 200; i++)
        a.pop();

    cout << a.front();
    return 0;
}

