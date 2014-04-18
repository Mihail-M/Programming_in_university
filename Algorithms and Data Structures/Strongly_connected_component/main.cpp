#include <iostream>
#include <vector>
using namespace std;

vector <int> g[100000], gr[100000];
int used[100000];
vector<int> order;
vector<int> comp;
void dfs1 (int v) {
	used[v] = true;
	for (int i=0; i< g[v].size(); ++i)
		if (!used[ g[v][i] ])
			dfs1 (g[v][i]);
	order.push_back (v);
}

void dfs2 (int v) {
	used[v] = true;
	comp.push_back(v + 1);
	for (int i=0; i<gr[v].size(); ++i)
		if (!used[ gr[v][i] ])
			dfs2 (gr[v][i]);
}

int main() {
	for(int i = 'A'; i <= 'K'; i++)
		cout << (char)i << " - >" << i-'A' + 1  << " ";
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		char t, t1;
		cin >> t >> t1;
		g[t - 'A'].push_back(t1 - 'A');
		gr[t1 - 'A'].push_back(t - 'A');
	}

	for (int i = 0; i < n; ++i)
		if (!used[i])
			dfs1 (i);
	int count = 0;

	for(int i = 0; i < n; i++)
		used[i] = 0;
	for (int i=0; i<n; ++i) {
		int v = order[n-1-i];
		if (!used[v]) {
			dfs2(v);
			for(int i = 0; i < comp.size(); i++)
				cout << comp[i] << " ";
						cout <<endl;
			comp.clear();
			count++;
		}
	}
	cout << count;
}
