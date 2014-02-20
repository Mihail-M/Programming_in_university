#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;


template <class T>
void merge(T *a, long int l,long int m,long int r){
	long int i = l, j = m + 1, pres = l;
    T *b = new T[r-l+1];
	while(i<=m && j<=r)
		if(a[i] < a[j])
		    b[pres++] = a[i++];
		else
            b[pres++] = a[j++];

	while(i<=m)
        b[pres++] = a[i++];

	while(j<=r)
        b[pres++] = a[j++];

	for(long int k = l; k <= r; k++)
        a[k] = b[k];
    delete[] b;
}
template <class T>
void merge_sort(T *a,long int l,long int r){
	long int m=(l+r) >> 1;

	if(l<r) {
		merge_sort(a,l,m);
		merge_sort(a,m+1,r);
		merge(a,l,m,r);
	}
}
template <class T>
bool is_ok(T *a, T *b, int n)
{
    for (int i = 0; i < n; i++)
        if(a[i] != b[i])
            return false;
    return true;
}

void test()
{
    for(int i = 1; i <= 7; i++)
    {
        string path = "test/test";
        path += i +'0';
        path += ".txt";
        ifstream in;
        in.open(path.c_str());
        int k = 0;
        in >> k;
        long int *a = new long int[k];
        long int *ans = new long int[k];

        for (int i = 0; i < k; i++)
        {
            in >> a[i];
            ans[i] = a[i];
        }

        sort(ans, ans + k);
        merge_sort(a, 0 , k-1);


        if(is_ok(a, ans, k))
            cout << path + " is ok!" << endl;
        else cout << "nine"<<endl;

        in.close();
        delete[] a;
        delete[] ans;
    }
}


int main()
{
    long int n = 0;
    test();
    cout << "input count of array: ";
    cin >> n;
    long int *a =  new long int[n];

    cout << "input array: ";
    for(long int i=0; i < n; i++)
      cin >> a[i];

    merge_sort(a, 0, n-1);

    for(long int i = 0; i < n; i++)
      cout << a[i] << " ";

    delete[] a;
    return 0;
}

