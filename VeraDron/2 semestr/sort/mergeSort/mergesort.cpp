#include <iostream>
#include <fstream>
#include <algorithm>
#include <test.h>

using namespace std;


template <class T>
void merge(T *a,int l, int m, int r){

    int i = l, j = m + 1, pres = l;
    T *b = new T[r-l+1];
    while (i<=m && j<=r)
        if (a[i] < a[j])
		    b[pres++] = a[i++];
		else
            b[pres++] = a[j++];

    while (i<=m)
        b[pres++] = a[i++];

    while (j<=r)
        b[pres++] = a[j++];

    for (int k = l; k <= r; k++)
        a[k] = b[k];
    delete[] b;
}

template <class T>
void merge_sort(T *a, int l, int r){
    long int m = (l + r) / 2;

	if(l<r) {
        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);
        merge(a, l, m, r);
	}
}


int main()
{
    long int n = 0;
    void (*f)(int*, int, int) = &merge_sort;
    test(f);
    cout << "input count of array: ";
    cin >> n;
    long int *a =  new long int[n];

    cout << "input array: ";

    for(int i=0; i < n; i++)
      cin >> a[i];

    merge_sort(a, 0, n-1);

    for(int i = 0; i < n; i++)
      cout << a[i] << " ";

    delete[] a;
    return 0;
}

