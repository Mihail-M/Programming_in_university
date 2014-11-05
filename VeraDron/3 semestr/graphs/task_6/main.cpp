#include <iostream>
#include <cstdio>
#include <queue>
#include "flow.h"

using namespace std;
using namespace Flow;


int main() {

    int n, m;
    cin >> n >> m;
    int **c;
    c = new int*[n + 1];
    for (int i = 0; i < n; i++)
        c[i] = new int[n];

    for(int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        c[x - 1][y - 1] = w;
    }

    cout << max_flow(0, n - 1, n, c);

    for(int i = 0; i < n; i++)
        delete[] c[i];
    delete[] c;
    return 0;
}
