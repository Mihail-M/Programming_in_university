#include <iostream>
#include <ctime>
#include <cstdlib>

#include "complexnumber.h"

using namespace std;

template <class T>
void bubbleSort(T *array, int l, int r)
{
    bool swapped = true;
    int i = 0;
    int n = r - l + 1;
    while(swapped)
    {
        swapped = false;
        i++;
        for(int j = 0; j < n - i; j++)
            if( array[j] > array[j+1])
            {
                swap(array[j], array[j+1]);
                swapped = true;
            }
    }
}

int main()
{
    srand(time(NULL));
    ComplexNumber a(1,2), b(1,34);
    a = a+b-b;
    a.print();
    a = ~a;
    a.print();
    int n;
    cout << "input n: ";
    cin >> n;

    ComplexNumber *complexArray = new ComplexNumber[n];
    for(int i = 0; i < n; i++) {
        complexArray[i] = ComplexNumber(rand()%200 - 100 + 1, rand()%200 - 100 + 1);
    }

    bubbleSort(complexArray, 0, n-1);

    for(int i = 0; i < n; i++) {
        complexArray[i].print();
    }
    delete[] complexArray;


    return 0;
}

