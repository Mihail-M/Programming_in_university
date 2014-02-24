#include <iostream>
#include <cstdlib>
#include <ctime>

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

    swap(A[i + 1], A[r]);
    return i+1;
}

int Randomized_Partition(int *A, int p ,int r)
{
    int i = rand() % (r - p) + p + 1;
    swap(A[i], A[r]);
    return Partition(A, p , r);
}

int nth_Element(int *A, int p, int r, int i)
{
    if(p == r)
        return A[p];
    int q = Randomized_Partition(A, p, r);
    int k = q - p + 1;
    if (i == k)
        return A[q];
    else if (i < k)
        return nth_Element(A, p, q-1, i);
    else return nth_Element(A, q+1, r, i - k);
}
int main()
{
    srand(time(NULL));
    int n;

    cout << "Input count of array: ";
    cin >> n;
    int *a = new int[n];

    cout << "Input array: ";

    for(int i = 0 ; i < n ; i ++)
        cin >> a[i];

    cout << "Input K: ";
    int k;
    cin >> k;
    cout << nth_Element(a, 0, n-1, k);

    delete[] a;
    return 0;
}
