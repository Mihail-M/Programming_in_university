#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;



int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    int *a = new int[n];
    int *d = new int[n];
    int *p = new int[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for (int i=0; i<n; ++i)
    {
        d[i] = 1;
        p[i] = -1;
        for (int j = 0; j < i; ++j)
            if (a[j] < a[i])
                if (d[j] +1 > d[i])
                {
                    d[i] = 1 + d[j];
                    p[i] = j;
                }
    }

    int ans = d[0],  pos = 0;

    for (int i = 0; i < n; ++i)
        if (d[i] > ans)
        {
            ans = d[i];
            pos = i;
        }

    cout << ans << endl;

    vector<int> path;
    while (pos != -1)
    {
        path.push_back (pos);
        pos = p[pos];
    }

    reverse (path.begin(), path.end());
    for (int i = 0; i < path.size(); ++i)
        cout << a[path[i]] << " ";

    delete[] a;
    delete[] d;
    delete[] p;
    return 0;
}
