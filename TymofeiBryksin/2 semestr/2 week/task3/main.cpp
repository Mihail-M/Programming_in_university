#include <iostream>
#include "bubblesorter.h"
using namespace std;

bool f(int *a, int *b){
    return a[0] > b[0];
}

void transposeMatrix(int **&arr, int &n, int &m) {

    int **b = new int*[m];
    for(int i = 0; i < m; i++)
        b[i] = new int[n];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            b[j][i] = arr[i][j];

    for(int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;
    arr = b;

    swap(n, m);
}

int main()
{
    int n = 0, m = 0;
    cout << "input n and m\n";
    cin >> n >> m;

    int **a = new int*[n];
    for(int i= 0; i < n; i++)
        a[i] = new int[m];

    cout << "input matrix:\n";

    for(int i= 0; i< n; i++)
        for(int j =0 ;j < m;j ++)
            cin >> a[i][j];

    transposeMatrix(a, n, m);

    BubbleSorter A;
    A.sort(a, 0, n-1, f);

    transposeMatrix(a, n, m);

    for(int i= 0; i < n; i++, cout << endl)
        for(int j = 0 ;j < m; j++)
           cout << a[i][j] << " ";


    return 0;
}

