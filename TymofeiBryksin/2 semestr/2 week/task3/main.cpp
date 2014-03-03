#include <iostream>
#include "bubblesorter.h"
using namespace std;

bool f(int *a, int *b){
    return a[0] > b[0];
}
int** transposeMatrix(int **arr, int &n, int &m) {//не знаю как передать этот двумерный массив по ссылке, чтобы сделать void

    int **b = new int*[m];
    for(int i = 0; i < m; i++)
        b[i] = new int[n];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            b[j][i] = arr[i][j];
    for(int i = 0; i < n; i++)
        delete[] arr;

    swap(n, m);
    return b;
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

    a = transposeMatrix(a, n, m);

    BubbleSorter A;
    A.sort(a, 0, n-1, f);
    a = transposeMatrix(a, n, m);
    cout << endl;

    for(int i= 0; i < n; i++, cout << endl)
        for(int j = 0 ;j < m; j++)
           cout << a[i][j] << " ";

    return 0;
}

