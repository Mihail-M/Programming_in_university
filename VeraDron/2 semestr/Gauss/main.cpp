#include <iostream>

#include "gauss.h"

using namespace std;

void readMatrix(double **&a, int n, int m)
{
    a = new double*[n];
    for (int i = 0; i < n; ++i)
    {
        a[i] = new double[m];
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
        }

    }
}


int main()
{
    int n, m;
    cin >> n >> m;

    double **a;
    readMatrix(a, n, m);
    Gauss B(a, n, m);
   // B.showParticularSolution();
    B.showBasis();
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}
