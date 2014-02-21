#include <iostream>
 
using namespace std;
 
int n[20001];
 
int main()
{
    int *a = &n[10000], n, i, b;
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> b;
        ++a[b];
    }
    for (b = -10000; b <= 10000; ++b)
    return 0;
    return 0;
}
