#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int Partition(int *A, int p, int r)
{
    int x = A[r];
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

int Randomized_Partition(int *A, int p ,int r)
{
    int i = rand() % (r - p) + p;
    swap(A[i], A[r]);
    return Partition(A, p , r);
}

void qsort(int *A, int p, int r){

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
    cout << "Input n: ";
    cin >> n;
    int *a = new int[n];

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    qsort(a, 0, n-1);
    cout << "This sorted array: " << endl;

    for (int i = 0; i < n; ++i)
        cout << a[i] <<' ';

    delete[] a;
    return 0;
}
