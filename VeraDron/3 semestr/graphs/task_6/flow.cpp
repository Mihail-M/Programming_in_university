#include "flow.h"

namespace Flow {

const int inf = (int)(1e+9);
int n, **f, **c,  *push, *parent;
bool *used;

void init(int s) {

    for(int i = 0; i < n; i++) {
        used[i] = parent[i] = push[i] = 0;
    }

    push[s] = inf;
    used[s] = 1;
    parent[s] = s;
}

bool bfs(int s, int t) {
    int k;
    init(s);
    queue <int> q;
    q.push(s);

    while(q.size() > 0 && !used[t]) {
        k = q.front();
        q.pop();
        for(int i = 0; i < n; i++)
            if(!used[i] && (c[k][i] - f[k][i] > 0)) {
                used[i] = 1;
                push[i] = min(push[k], c[k][i] - f[k][i]);
                parent[i] = k;
                q.push(i);
            }
    }
    return used[t];
}

int max_flow(int s, int t, int _n, int **c_) {
    int ans = 0;
    //---------------------
    //init
    n = _n;
    push = new int[n];
    parent = new int[n];
    used = new bool[n];
    c = c_;

    f = new int*[n];
    for (int i = 0; i < n; i++)
        f[i] = new int[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            f[i][j] = 0;
    //----------------------

    while(bfs(s, t)) {
        int add = push[t];
        int v = parent[t];
        int u = t;

        while(v != u) {
            f[v][u] += add;
            f[u][v] -= add;
            u = v;
            v = parent[u];
        }
        ans += add;
    }
    delete[] push;
    delete[] parent;
    delete[] used;
    for(int i = 0; i < n; i++)
        delete[] f[i];
    delete[] f;
    return ans;
}


}
