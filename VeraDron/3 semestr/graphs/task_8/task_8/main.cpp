#include <algorithm>
#include <vector>
#include <iostream>
#include <set>

#include "kuhn.h"
using namespace std;
int inf = 10e9;
int n;

vector <bool> used;
vector <bool> isRight;


void reduction(int **&a, int n)
{
	
	for (int i = 0; i < n; i++)
	{

		int _min = a[0][i];
		for (int k = 0; k < n; k++)
			_min = min(_min, a[k][i]);

		for (int j = 0; j < n; j++)
			a[j][i] -= _min;
	}

}


// Обход в глубину для переключения ребер паросочетания
void controlVisit(int s, vector<vector<int> > &graph, vector <int>& match)
{
	used[s] = true;
	for (int it = 0; it < graph[s].size(); it++) {
		if (!isRight[graph[s][it]] && !used[match[graph[s][it]]])
		{
			controlVisit(match[graph[s][it]], graph, match);
			isRight[graph[s][it]] = true;
		}
	}
}

// Поиск наименьшего контролирующего множества
pair <vector<int>, vector<int> > getControlSet(vector<vector<int> > &graph, vector<int> &match)
{

	//свободные вершинки в левой доли
	vector<bool> isFree(n, 1);

	for (int i = 0; i < n; i++)
		if (match[i] != -1)
			isFree[match[i]] = 0;


	isRight.assign(n, 0);
	used.assign(n, 0);
	for (int i = 0; i < n; i++)
		if (isFree[i])
			controlVisit(i, graph, match);

	pair<vector<int>, vector<int>> result;
	for (int i = 0; i < n; i++) {
		if (match[i] != -1)
		{
			if (isRight[i])
				result.second.push_back(i);
			else
				result.first.push_back(match[i]);
		}
	}
	return result;
}

void updatePotentialMatrix(int delta, int **&b, vector<int>& Z1, vector<int>& Z2) {
	
	for (int i = 0; i < n; ++i)
		if (Z1[i] == 1)
			for (int j = 0; j < n; ++j)
				b[i][j] += delta;

	for (int j = 0; j < n; ++j)
		if (Z2[j] == -1)
			for (int i = 0; i < n; ++i)
				b[i][j] -= delta;
}

int get_delta(vector <int> & Z1, vector <int> &Z2, vector <int>& match, int **b )
{
	int delta = 1e9;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (Z1[i] == -1 && Z2[j] == -1 && b[i][j] < delta)
				delta = b[i][j];

	return delta;
}

int main()
{

	cin >> n;

	int **a = new int*[n];
	int **b = new int*[n];

	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
		b[i] = new int[n];
	}


	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j], b[i][j] = a[i][j];

	// сделали редукцию по строкам и столбцам
	while (1) {
		reduction(a, n);

		vector <vector <int> > gr(n);
		//граф из жестких ребер
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (a[i][j] == 0)
					gr[i].push_back(j);


		//нашел паросочетание
		vector< pair <int, int> > maxMatching_pairFormat = graph::Kuhn::MaxMatching::getMaxMatching(n, n, gr);
		vector <int> maxMatching(n, -1);

		for (int i = 0; i < maxMatching_pairFormat.size(); i++)
			maxMatching[maxMatching_pairFormat[i].first - 1] = maxMatching_pairFormat[i].second - 1;

		if (maxMatching_pairFormat.size() == n) {
			int sum = 0;
			for (int i = 0; i < maxMatching_pairFormat.size(); i++)
				sum += b[maxMatching_pairFormat[i].second - 1][maxMatching_pairFormat[i].first - 1];

			cout << sum << " done!";
			return 0;
		}



		//теперь попробуем найти контролирующее множество, минимальное

		pair <vector<int>, vector<int> > controlSet = getControlSet(gr, maxMatching);
		vector <int> Z1(n, -1), Z2(n, -1);

		for (int i = 0; i < controlSet.first.size(); i++)
			Z1[controlSet.first[i]] = 1;
		for (int i = 0; i < controlSet.second.size(); i++)
			Z2[controlSet.second[i]] = 1;


		int delta = get_delta(Z1, Z2, maxMatching, a);
		updatePotentialMatrix(delta, a, Z1, Z2);
	}

}





