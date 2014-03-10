#include <iostream>
#include "array.h"
using namespace std;

int main()
{
    Array<int> x(10);
    for (int i = 0; i < x.getSize(); i++)
        x[i] = i;
    Array <int> y = x;
    for (int i = 0; i < y.getSize(); i++)
        cout << y[i] << " ";
    cout << endl;
    Array<int> z(5);
    z[0] = z[1] = z[2] = z[3] = z[4] = 0;
    for (int i = 0; i < z.getSize(); i++)
        cout << z[i] << " ";
    cout << endl;

    z = y;
    for (int i = 0; i < z.getSize(); i++)
        cout << z[i] << " ";
    cout << endl;
    z = z;
    for (int i = 0; i < z.getSize(); i++)
        cout << z[i] << " ";


    return 0;
}

