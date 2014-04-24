#include "gauss.h"
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

/// вспомогательная функция для инициализации матриц
double **init(double **a, int n, int m) {
	double **b = new double*[n];
	for (int i = 0; i < n; ++i) {
		b[i] = new double[m];
		for (int j = 0; j < m; ++j) {
			b[i][j] = a[i][j];
		}

	}
	return b;
}


Gauss::Gauss(double **A, int n, int m):
	triangled(false)
  , countOfRows(n)
  , countOfColumns(m) {
	matrix = new double*[n];
	for (int i = 0 ; i < n; i++)
		matrix[i] = new double[m];

	for (int i = 0 ; i < n; i++)
		for (int j = 0; j < m; j++)
			matrix[i][j] = A[i][j];
	where = new int[m];

}

Gauss::~Gauss() {
	for (int i = 0; i < countOfRows; i++)
		delete[] matrix[i];
	delete[] matrix;
	delete[] particularSolution;
	delete[] where;
}

void Gauss::show() {
	for (int i = 0; i < countOfRows; i++, std::cout << std::endl)
		for (int j = 0; j < countOfColumns; j++)
			cout << (abs(matrix[i][j]) < EPS ? 0: matrix[i][j]) << " ";
}

void Gauss::toTriangle()
{

	if(triangled) return;

	triangled = true;
	int m = countOfColumns - 1;
	int n = countOfRows;

	for(int i = 0; i < m; i++)
		where[i] = -1;

	for (int col = 0, row = 0; col < m && row < n; ++col) {
		int sel = row;
		for (int i = row; i < n; ++i)
			if (abs(matrix[i][col]) > abs(matrix[sel][col]))
				sel = i;

		if (abs(matrix[sel][col]) < EPS)
			continue;

		for (int i = col; i <= m; ++i)
			swap (matrix[sel][i], matrix[row][i]);
		where[col] = row;

		for (int i = 0; i < n; ++i)
			if (i != row) {
				double c = matrix[i][col] / matrix[row][col];
				for (int j = col; j <= m; ++j)
					matrix[i][j] -= matrix[row][j] * c;
			}

		++row;
	}
}

bool Gauss::showParticularSolution()
{
	if (getParticularSolution() == 0) {
		std::cout << "NO SOLUTION" << std::endl;
		return 0;
	}
	else
	{
		for (int i = 0; i < countOfColumns - 1; i++)
			std::cout << (abs(particularSolution[i]) < EPS ? 0 : particularSolution[i]) << " ";
		std::cout << std::endl;
		return 1;
	}
}

void Gauss::getParticularSolution(int n) {
	double **b = init(matrix, countOfRows, countOfColumns);

	for (int i = 0; i < countOfRows; i++ ) {
		if (abs(matrix[i][n]) < EPS ) {
			matrix[i][countOfColumns - 1] = 0;
		}
		else {
			matrix[i][countOfColumns - 1] = -matrix[i][n];
			matrix[i][n] = 0;
		}
	}

	if (getParticularSolution())
		particularSolution[n] = 1;

	for (int i = 0; i < countOfRows; i++)
		for(int j = 0; j < countOfColumns; j++)
			matrix[i][j] = b[i][j];

	for(int i = 0; i < countOfRows; i++)
		delete[] b[i];
	delete[] b;
}

void Gauss::showBasis() {

	int rank = getRank();
	double **answer = basis();
	for (int i = 0; i <= rank; i++, cout << endl)
		for (int j = 0; j < countOfColumns - 1; j++)
			cout << answer[i][j] << " ";

	for (int i = 0; i <= rank; i++)
		delete[] answer[i];
	delete[] answer;

}

int Gauss::getRank() {
	if (rank != -1)
		toTriangle();

	int c = 0;
	for(int i = 0 ;i < countOfColumns; i++)
		if(where[i] == -1) c++;
	rank = c;

	return rank;
}

double **Gauss::basis() {

	if (getParticularSolution()) {

		int rank = getRank();
		double **answer = new double*[rank + 1];
		for (int i = 0; i <= rank; i++)
			answer[i] = new double[countOfColumns - 1];

		for(int i = 0; i < countOfColumns - 1; i++)
			answer[0][i] = particularSolution[i];

		int *free = new int[rank];

		for(int i = 0, j = 0; i < countOfColumns; i++)
			if (where[i] == -1) {
				free[j++] = i;
			}

		for(int k = rank - 1; k >= 0 ; k--) {
			getParticularSolution(free[k]);
			for(int i = 0; i < countOfColumns - 1; i++)
				answer[k + 1][i] = particularSolution[i];
		}
		delete[] free;
		return answer;
	}

	return nullptr;

}

int Gauss::getParticularSolution() {

	toTriangle();

	particularSolution = new double[countOfColumns - 1];

	for (int i = 0; i < countOfColumns - 1; i++)
		if (where[i] != -1)
			particularSolution[i] = matrix[where[i]][countOfColumns - 1] / matrix[where[i]][i];
		else particularSolution[i] = 0 ;

	for (int i = 0; i < countOfRows; ++i) {
		double sum = 0;
		for (int j = 0; j < countOfColumns - 1; j++)
			sum += particularSolution[j] * matrix[i][j];
		if (abs (sum - matrix[i][countOfColumns - 1]) > EPS)
			return 0;
	}

	for (int i = 0; i < countOfColumns - 1; i++)
		if (where[i] == -1)
			return INF;
	return 1;
}

