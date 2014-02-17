#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    float *q = (float*)&n;
    cout << *q;


    return 0;
}
