#include <iostream>
#include "bubblesorter.h"
#include "mergesorter.h"


using namespace std;

bool f(int a,int b) {
    return a  <= b;
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

    BubbleSorter A;
    MergeSorter B;

    A.sort(a, 0, n-1);

    cout << "This is bubblesorted array: \n";

    for(int i = 0; i < n; i++)
       cout << a[i] << " ";

    B.sort(a, 0, n - 1);
    cout << "\nThis is mergesorted array: \n";

    for(int i = 0; i < n; i++)
       cout << a[i] << " ";

    return 0;
}

