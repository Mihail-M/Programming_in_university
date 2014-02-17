#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits.h>
using namespace std;

void qsort(int l, int r, int*& a)
{
    int x, i, j;
    i = l;
    j = r;
    x = a[rand() % (r + 1)];
    while (i <= j)
    {
        while (a[i] < x)
            i++;

        while (a[j] > x)
            j--;

        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (l < j)
        qsort(l, j, a);

    if (i < r)
        qsort(i, r, a);
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

    qsort(0, n - 1, a);
    cout << "This max: " << endl;
    bool flag = false;
    for (int i = n - 1; i >= 1; i--)
        if (a[i] == a[i - 1]){
            cout<<a[i];
            flag = true;
            break;
        }
    if (!flag)
        cout << "not exist!!!!";

    delete[] a;
    return 0;
}