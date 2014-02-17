#include <cstdio>
#include <iostream>
using namespace std;
const int INF = 1000000;

int dist[105];
int parent[105] = {-1};
int n, m, start;

int g[105][105];
bool used[105];

void printer(int pos, int finalPos)
{
    if(pos != finalPos - 1)
    {
        printer(parent[pos], finalPos);
        cout << pos+1 << " ";
    }
}

void djktsra(int start)
{

    dist[start] = 0;

    for(int i = 0; i < n*n; ++i)
    {
        int min_dist = INF;
        int cur = -1;

        for(int j = 0; j < n; ++j)
            if(!used[j] && dist[j] < min_dist)
            {
                min_dist = dist[j];
                cur = j;
            }

        if(cur == -1) break;

        for(int j = 0; j < n; j++)
            if(g[cur][j] != -1 && cur != j)
            {
                if(dist[j] > dist[cur] + g[cur][j])
                {
                    parent[j] = cur;
                    dist[j] = dist[cur] + g[cur][j];
                }
            }
        used[cur] = true;

    }
}

int minInd(int arr[],int n)
{
    int minI = 0, minValue = INF;
    for(int i = 0; i < n; i++)
        if(minValue > arr[i])
        {
            minValue = arr[i];
            minI = i;
        }
    return minI;

}
int main()
{
    cout << "Input count of node and edges and start node" << endl;
    cin >> n >> m >> start;

    for(int i = 0; i < n; i++)
        dist[i] = INF;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            g[i][j] = -1;

    for(int i = 0; i < m; i++)
    {
        int from, to, ceil;
        cin >> from >> to >> ceil;
        g[from - 1][to - 1] = ceil;
    }

    djktsra(start - 1);
    dist[start - 1] = INF;
    for(int i = 0; i < n; i++)
    {
        int curInd = minInd(dist, n);
        if (dist[curInd] == INF) {}
        else
        {

            cout <<"Town " << curInd  + 1 << ": distance - " << dist[curInd] <<endl;
            cout << "Way is: "
            printer(curInd , start - 1);
            cout << endl;
            dist[curInd] = INF;
        }
    }

    return 0;
}
