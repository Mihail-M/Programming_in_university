#include <iostream>
#include <vector>

using namespace std;
struct Edge {
	int in, to, cost;
	Edge(int _in, int _to, int _cost) {
		in = _in, to = _to, cost = _cost;
	}
};

int n, m;

int const INF = 1e9;

vector <Edge> g;

int d[10000000];

void find_circle() {
	int x;
	for (int i = 0; i < n; ++i) {
		x = -1;
		for (int j = 0; j < m; ++j)

			if (d[g[j].to] > d[g[j].in] + g[j].cost) {
				d[g[j].to] = max (-INF, d[g[j].in] + g[j].cost);
				x = g[j].to;
			}
	}

	if (x == -1)
		cout << "False";
	else cout << "True";
	return;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		g.push_back(Edge(a, b, c));
	}
	for (int i = 0; i < n; i++)
		d[i] = INF;

	find_circle();
	return 0;
}

