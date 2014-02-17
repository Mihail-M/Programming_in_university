#include <iostream>

using namespace std;
void binSearch(int a[], int x)
{
    int l=0, r = 50;
    int m,count = 0;
    while (l<r)
    {
        count++;
        m=(l+r)/2;
        if (a[m]<x) l=m+1;
        else r=m;
    }
    cout << "index: ";
    if (a[r]==x) cout << r;
    else cout << "-1";
    cout << "count: " << count;
}
int main()
{
    int m[50];
    for(int i=0; i < 50; i++)
        cin >> m[i];
    int x;
    cin >> x;
    binSearch(m, x);
    return 0;

}
