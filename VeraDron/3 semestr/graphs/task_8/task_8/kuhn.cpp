#include "kuhn.h"
#include <cstring>
#include <iostream>

namespace graph
{

namespace Kuhn {

bool *MaxMatching::used = NULL;
int *MaxMatching::mt = NULL;
vector< pair <int, int> > MaxMatching::getMaxMatching(int n, int m,vector<vector<int> > &gr)
{
    vector <pair <int, int> > ans;
    mt = new int[m];
    used = new bool[n];

    memset(mt, -1, m*sizeof(int));
    for (int i = 0; i < n; i++) {
        memset(used, 0, n*sizeof(bool));
        kuhn(i, gr);
    }

    for(int i = 0; i < m; i++)
        if (mt[i] != -1)
			ans.push_back(make_pair(i + 1, mt[i] + 1));

    delete[] used;
    delete[] mt;
    return ans;
}

bool MaxMatching::kuhn(int v, vector<vector<int> > &gr)
{
    if (used[v])
        return false;
    used[v] = true;

    for (size_t i = 0; i < gr[v].size(); i++) {
        int to = gr[v][i];
        if (mt[to] == -1 || kuhn (mt[to], gr)) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

}
}
