#include <iostream>
#include "bubblesorter.h"

using namespace std;

bool f(int a,int b){
    return a < b;
}

int main()
{
    int *a = new int[5];
    cout << "input 5 array elements:\n";
    for(int i =0 ;i < 5; i++)
        cin >> a[i];

    BubbleSorter b(a);

    a =  b.getSortArray(0, 4, f);

    for(int i = 0; i < 5; i++)
        cout << a[i] << " ";

    return 0;
}

