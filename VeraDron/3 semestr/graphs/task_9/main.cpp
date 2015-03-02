#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <algorithm>

#include <limits.h>
using namespace std;



int edge_cost(int s, int f, vector<vector<int> > & capacities, vector <vector<int> > & flow,vector<vector<int> >& cost) {
    if (capacities[s][f] - flow[s][f] > 0)
        return cost[s][f];
    else return INT_MAX;

}
vector<int> parent (10000 + 1, -1);

int Ford_Bellman(vector<vector<int> > & capacities, vector <vector<int> > & flow,vector<vector<int> >& cost, int s, int n)
{
    vector<int> dist (n, INT_MAX);
    queue<int> q;
    parent[s] = s;
    dist[s] = 0;

    q.push(s);
    q.push(-1);

    int u, count = 0;
    while( !q.empty() )
    {

        while( q.front() == -1 )
        {
            q.pop();
            if( ++count > n+1) {//если продолжается релаксация, значит есть отрицательный цикл
                for(int u = 0; u < n; u++)
                    for(int v = 0; v < n; v++)
                        if( dist[v] > dist[u] + edge_cost(u, v, capacities,flow,cost) )
                            return u;
                return -1;
            }

            else q.push(-1);
        }

        u = q.front();
        q.pop();
        for(int v = 0; v < n; v++)
            if( dist[v] > dist[u] + edge_cost(u, v, capacities,flow,cost) )
            {
                dist[v] = dist[u] + edge_cost(u, v, capacities,flow,cost);
                parent[v] = u;
                q.push(v);
            }
    }
}

bool bfs(vector<vector<int> >& capacities,vector<vector<int> > &flow, int s, int f, vector<int>& parents, int n) {
    queue<int> queue;
    vector<bool> visited(n, false);
    parents[s] = -1;
    visited[s] = true;
    queue.push(s);
    while (!queue.empty()) {
        int from = queue.front();
        queue.pop();
        for (int i = 0; i < n; i++) {
            if (!visited[i] && capacities[from][i] - flow[from][i] > 0) {
                queue.push(i);
                parents[i] = from;
                visited[i] = true;
            }
        }
    }
    return visited[f];
}

int edmonds_karp(vector<vector<int> >& capacities, vector<vector<int> >& flow, int s, int f, int n){
    int u, v;
    vector<int> parents(n, -1);
    int max_flow = 0;
    while (bfs(capacities, flow, s, f, parents, n)){
        int path_flow = INT_MAX;
        for (v = f; v != s; v = parents[v]){
            u = parents[v];
            path_flow = min(path_flow, capacities[u][v] - flow[u][v]);
        }

        for (v = f; v != s; v = parents[v]) {
            u = parents[v];
            flow[u][v] += path_flow;
            flow[v][u] -= path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

//баг здесь!!!
int min_cost_max_flow(vector<vector<int> >& capacities,vector<vector<int> >& cost , int s, int f, int n)
{
    vector< vector<int> > flow(n, vector<int>(n, 0));

    int max_flow = edmonds_karp(capacities, flow, 0, n - 1, n);

    int u, v = 0;
    int add = INT_MAX;
    int neg_cycle;
    int min_cost = 0;
    neg_cycle = Ford_Bellman(capacities, flow, cost, n-1, n);
    while( neg_cycle != -1 )
    {
        for (int v = neg_cycle, u = parent[v], i = 0; v != neg_cycle || !i; v = u, u = parent[v]) {
            add = min(add, capacities[u][v] - flow[u][v]);
            i++;

        }

        for (int v = neg_cycle, u = parent[v], i = 0; v != neg_cycle || !i; v = u, u = parent[v]){
            flow[u][v] += add;
            flow[v][u] -= add;
            i++;
        }

        neg_cycle = Ford_Bellman(capacities, flow, cost, n-1, n);
    }


    for(int u = 0; u < n; u++)
        for(int v = 0; v < n; v++)
            if( flow[u][v] > 0 )
                min_cost += flow[u][v] * cost[u][v];

    cout << max_flow << " ";
    return min_cost;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > gr(n, vector<int>(n, 0));
    vector<vector<int> > NowCost(n, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        int from, to, w, cost;
        cin >> from >> to >> w >> cost;
        gr[from - 1][to - 1] = w;
        NowCost[from - 1][to - 1] = cost;
        NowCost[to - 1][from - 1] = -cost;

    }
    cout << min_cost_max_flow(gr,NowCost, 0, n - 1, n);
    return 0;
}
