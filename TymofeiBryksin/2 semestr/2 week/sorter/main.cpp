#include <iostream>
#include "bubblesorter.h"
#include "mergesorter.h"

using namespace std;

bool f(int a,int b) {
    return a > b;
}

int main()
{
    int n = 0;

    cout << "input n:\n";

    cin >> n;

    int *a = new int[n];
    cout << "input n array elements:\n";

    for(int i = 0 ;i < n; i++)
        cin >> a[i];

    BubbleSorter A(a);
    MergeSorter B(a);

    a =  A.getSortArray(0, n - 1, f);

    cout << "This is bubblesorted array: \n";

    for(int i = 0; i < n; i++)
       cout << a[i] << " ";

    cout << "\nThis is mergesorted array: \n";
    a =  B.getSortArray(0, n - 1, f);

    for(int i = 0; i < n; i++)
       cout << a[i] << " ";

    return 0;
}

