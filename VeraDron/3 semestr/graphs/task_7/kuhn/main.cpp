#include <iostream>
#include "kuhn.h"

using namespace std;
using namespace graph::Kuhn;



int main()
{
    vector <vector<int> > gr;
    int n, m;
    cin >> n >> m;

    for (int i  = 0; i < n; ++i){
        vector <int> grT;
        gr.push_back(grT);
        for (int j = 0; j < m; ++j)
        {
            int t;
            cin >> t;
            if (t == 1)
                gr[i].push_back (j);
        }
    }

    vector < pair<int, int> > ans = MaxMatching::getMaxMatching(n , m , gr);

    cout << ans.size() << endl;

    for (int i = 0; i < ans.size(); i++)
            cout << ans[i].first << " " << ans[i].second << endl;

    return 0;
}

