#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include "test.h"

using namespace std;

template <class T>
int Partition(T *A, int p, int r)
{
    T x = A[r];
    int i = p - 1;

    for (int j = p; j <= r - 1; j++)
        if (A[j] <= x)
        {
            i++;
            swap(A[i], A[j]);
        }

    swap(A[i+1], A[r]);
    return i + 1;
}
template <class T>
int Randomized_Partition(T *A, int p ,int r)
{
    int i = rand() % (r - p) + p;
    swap(A[i], A[r]);
    return Partition(A, p , r);
}

template <class T>
void qsort(T *A, int p, int r){

    if(p < r){
        int q = Randomized_Partition(A, p, r);
        qsort(A, p, q - 1);
        qsort(A, q + 1, r);
    }

}


int main()
{
    srand(time(NULL));
    int n;
    void (*f)(int * , int, int) = &qsort;

    test(f);

    cout << "Input n: ";
    cin >> n;
    int *a = new int[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    qsort(a, 0, n-1);
    cout << "This sorted array: " << endl;

    for (int i = 0; i < n; i++)
        cout << a[i] <<' ';

    delete[] a;
    return 0;
}
