#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    int a, b, c;
    cin >> n >> a >> b >> c;
    cout << max( 0 , n-a) << " " << max(0, n-b) << " " << max(0, n - c);
    return 0;
}
