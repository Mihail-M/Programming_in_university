#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void find_bridges (int from, int parent,
                   int *used , int *tin, int *fup, int timer
                   , vector <vector <int> > &g
                   , vector <pair <int,int> > &ans)
{
	used[from] = true;
	tin[from] = fup[from] = timer++;

	for (size_t i = 0; i < g[from].size(); i++)
    {
		int to = g[from][i];
		if (to == parent)
            continue;
		if (used[to])
        {
			fup[from] = min (fup[from], tin[to]);
        }
		else
        {
			find_bridges (to, from, used, tin, fup, timer, g, ans);
			fup[from] = min (fup[from], fup[to]);
			if (fup[to] > tin[from])
                    ans.push_back(make_pair(from, to));

		}
	}
}


int main()
{

    int n;
    cin >> n;
    int *used = new int[n];
    int *tin = new int[n];
    int *fup = new int[n];
    memset(used, 0, sizeof(int)*n);
    memset(tin, 0, sizeof(int)*n);
    memset(fup, 0, sizeof(int)*n);
    cout << tin[3];
    vector <vector <int> > g;
    for(int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        vector <int> temp;
        for(int j = 0; j < m; j++)
        {
            int t = 0;
            cin >> t;
            temp.push_back(t);
        }
        g.push_back(temp);
    }
    vector <pair <int, int > > ans;
	for (int i = 0; i < n; i++)
		if (!used[i])
			find_bridges (i, -42, used, tin, fup, 0, g , ans);

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second << endl;

    return 0;
}
