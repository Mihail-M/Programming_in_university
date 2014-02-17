#include <iostream>

using namespace std;

void F(int **&a, int k, int n, int m)
{
    int **b = new int*[n+1];
    int *c = new int [m];
    for (int i = 0; i<m; i++) c[i]=0;
    for (int i=0; i<k; i++)
    {
        for (int j=0; j<m; j++)
            c[j]+=a[i][j];
        b[i] = a[i];
    }
    b[k] = new int[m];
    b[k] = c;
    for (int i = k; i < n; i++)
    {
        b[i+1]=a[i];
    }
    delete [] a;
    a = b;
}

int main()
{
    int n,m;
    cin >> n >> m;
    int **a = new int *[n];
    for (int i=0; i < n; i++)
    {
        a[i] = new int[m];
        for (int j=0; j<m; j++)
            a[i][j] = i + 1;
    }
    for (int i=0; i < n; i++)
    {
        for (int j=0; j<m; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
    F(a,3,n,m);
    for (int i=0; i <= n; i++)
    {
        for (int j=0; j<m; j++)
            cout << a[i][j] << ' ';
        cout << endl;
        delete[] a[i];
    }
    delete[] a;
    return 0;
}
