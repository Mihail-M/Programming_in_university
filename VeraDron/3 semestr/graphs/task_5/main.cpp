#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Kruskal(vector < pair < int, pair<int,int> > > &g, int n, int m) {
    int cost = 0;
    sort(g.begin(), g.end());

    vector<int> treeId(n);
    for(int i = 0; i < n; i++)
        treeId[i] = i;

    for (int i = 0; i < m; i++)
    {
        int from = g[i].second.first,  to = g[i].second.second,  _cost = g[i].first;

        if (treeId[from] != treeId[to])
        {
            cost += _cost;

            int old = treeId[to];
            int notOld = treeId[from];
            for (int j = 0; j < n; j++)
                if (treeId[j] == old)
                    treeId[j] = notOld;
        }
    }

    return cost;
}


int main()
{

    int n, m;
    cin >> n >> m;

    vector < pair < int, pair<int,int> > > g;

    for(int i = 0; i < m; i++)
    {
        int _cost ,to ,from;
        cin >> to >> from >> _cost;
        g.push_back(make_pair(_cost, make_pair(to - 1, from - 1)));
    }

    cout << Kruskal(g, n, m);


    return 0;

}
