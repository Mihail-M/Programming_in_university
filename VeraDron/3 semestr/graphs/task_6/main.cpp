#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <limits.h>
using namespace std;


bool bfs(vector<vector<int> >& capacities, int s, int f, vector<int>& parents, int n) {
    queue<int> queue;
    vector<bool> visited(n, false);
    parents[s] = -1;
    visited[s] = true;
    queue.push(s);
    while (!queue.empty()){
        int from = queue.front();
        queue.pop();
        for (int i = 0; i < n; i++){
            if (!visited[i] && capacities[from][i] > 0) {
                queue.push(i);
                parents[i] = from;
                visited[i] = true;
            }
        }
    }
    return visited[f];
}

int edmonds_karp(vector<vector<int> >& capacities, int s, int f, int n){
    int u, v;
    vector<int> parents(n, -1);
    int max_flow = 0;
    while (bfs(capacities, s, f, parents, n)){
        int path_flow = INT_MAX;
        for (v = f; v != s; v = parents[v]){
            u = parents[v];
            path_flow = min(path_flow, capacities[u][v]);
        }

        for (v = f; v != s; v = parents[v]) {
            u = parents[v];
            capacities[u][v] -= path_flow;
            capacities[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > gr(n, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        gr[from - 1][to - 1] = cost;
    }
    cout << edmonds_karp(gr, 0, n - 1, n);
    return 0;
}
