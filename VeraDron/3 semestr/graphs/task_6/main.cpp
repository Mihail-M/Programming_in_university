#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

const int inf = (int)(1e+9);

int n, m, c[1050][1050], f[1050][1050]
        , push[1050], parent[1050];

bool used[1050];

void init(int s) {
    for(int i = 1; i <= n; i++) {
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
        for(int i = 1; i <= n; i++)
            if(!used[i] && (c[k][i] - f[k][i] > 0)) {
                used[i] = 1;
                push[i] = min(push[k], c[k][i] - f[k][i]);
                parent[i] = k;
                q.push(i);
            }
    }
    return used[t];
}

int max_flow(int s, int t) {
    int ans = 0;

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

    return ans;
}

int main() {

    int x, y, w;

    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        cin >> x >> y >> w;
        c[x][y] = w;
    }

    cout << max_flow(1, n);
    return 0;
}
