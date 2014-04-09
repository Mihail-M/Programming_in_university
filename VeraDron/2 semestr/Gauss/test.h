#include "gauss.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;
bool is_ok(double **a, double **b, int n, int m) {
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if (abs(a[i][j] - b[i][j]) >= 1e-4){
				return 0;
			}
	return 1;
}

void test() {
	for (int i = 1; i <= 5; i++)
	{
		string pathToTest = "test/input/test";
		pathToTest += i +'0';
		pathToTest += ".txt";
		ifstream in(pathToTest.c_str());

		int n = 0, m = 0;
		in >> n >> m;
		double **mas = new double*[n];
		for (int j = 0; j < n; j++){
			mas[j] = new double[m];
		}
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
				in >> mas[j][k];

		Gauss b(mas, n, m);

		for(int q = 0; q < n; q++)
			delete[] mas[q];

		n = b.getRank() + 1;

		mas = b.basis();

		string pathToAns = "test/answer/ans";
		pathToAns += i +'0';
		pathToAns += ".txt";
		std::ifstream in1;
		in1.open(pathToAns.c_str());
		int n1, m1;

		in1 >> n1 >> m1;

		if (mas ==  nullptr)
		{
			cout << pathToTest << " Ok!" << endl;
			continue;
		}

		double **ans = new double*[n1];
		for (int j = 0; j < n1; j++)
			ans[j] = new double[m1];

		for (int j = 0; j < n1; j++)
			for (int k = 0; k < m1; k++)
				in1 >> ans[j][k];

		if (is_ok (mas, ans, n1, m1))
			cout << pathToTest << " Ok!" << endl;
		else cout << pathToTest << "Failed(" << endl;

		for(int q = 0; q < n; q++)
			delete[] mas[q];

		for (int q = 0; q < n1; q++)
			delete[] ans[q];

		delete mas;
		delete ans;
	}
}
