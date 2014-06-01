#include <iostream>
#include <cstring>
#include <cstdio>
#include "fraction.h"

#include <fstream>

using namespace std;
const int MaxSize = 100;

void SwapLine(Fraction Matr[MaxSize][MaxSize], int a, int b)
{
	for (int i = 0; i < MaxSize; i++)
		swap(Matr[a][i], Matr[b][i]);
}

void UmnozLine(Fraction Matr[MaxSize][MaxSize], int a, int n, Fraction x)
{
	for (int i = 0; i<n; i++)
		Matr[a][i] = Matr[a][i] * x;
}
void MinusLine(Fraction Matr[MaxSize][MaxSize], int a, int b, int n)
{
	for (int i = 0; i<n; i++)
		Matr[a][i] = Matr[a][i] - Matr[b][i];
}

void read_matr(Fraction a[MaxSize][MaxSize], int &m, int &n, const char *s)
{
	ifstream F;
	F.open(s);
	F >> m; F >> n;

	for (int i = 0; i < m; i++)
	for (int j = 0; j < n; j++) {

		int t;
		F >> t;
		a[i][j] = t;


	}
	F.close();
}

void write_matr(Fraction a[MaxSize][MaxSize], int &m, int &n)
{

	cout << endl;

	for (int i = 0; i < m; i++,cout << endl)
	for (int j = 0; j < n; j++) 

		cout << a[i][j].getValue() << " ";

	cout << endl;


	
}

void write_matr(double a[MaxSize][MaxSize], int &m, int &n)
{
	cout << endl;
	for (int i = 0; i < m; i++, cout << endl)
	for (int j = 0; j < n; j++)

		cout << a[i][j] << " ";
	cout << endl;


}


void read_matr(double a[MaxSize][MaxSize], int &m, int &n, const char *s)
{
	ifstream F;
	F.open(s);
	F >> m; F >> n;

	for (int i = 0; i < m; i++)
	for (int j = 0; j < n; j++) {
		F >> a[i][j];
	}
	F.close();
}

void Make_Triangle(Fraction a[MaxSize][MaxSize], int m, int n)
{
	int r = 0;
	for (int k = 0; (k<m - 1) && (r<n); ++k)
	{
		int MaxIndex = k;
		for (int j = k + 1; j<m; j++)
		if (abs(a[j][r]) > abs(a[MaxIndex][r]))
			MaxIndex = j; 

		SwapLine(a, k, MaxIndex);
		if (a[k][r]<Fraction(0))
			UmnozLine(a, k, n, (-1));
		if (a[k][r] == Fraction(0))
		{
			r++;
			k--;
		}
		else
		{
			for (int j = k + 1; j<m; j++)
			if (a[j][r] != Fraction(0))
			{
				UmnozLine(a, j, n, (a[k][r] / a[j][r]));
				MinusLine(a, j, k, n);
			}
			r++;
		}
	}
}

bool Exist_Solut(Fraction a[MaxSize][MaxSize], int m, int n)
{
	for (int i = 0; i<m; i++)
	{
		bool bol = true;
		for (int j = 0; j<n - 1; j++)
		if (a[i][j] != Fraction(0))
			bol = false;
		if (bol && (a[i][n - 1] != Fraction(0)))
			return false;
	}
	return true;
}

void Find_Svoboda(Fraction a[MaxSize][MaxSize], int m, int n, bool svoboda[MaxSize])
{
	int l = 0;
	int j = n - 2;
	for (int i = m - 1; i >= 0; i--) // ищем свободные переменные
	{
		l = 0;
		while ( (a[i][l] == 0) && (l <= j) )
			++l;

		for (int k = l + 1; (k <= j); ++k)
			svoboda[k] = true;
		j = l - 1;
	}

	if (a[0][0] == 0)
		svoboda[0] = true;  // Свободные находятся верно
}

void Partial_Solution(Fraction a[MaxSize][MaxSize], int m, int n, Fraction solut[MaxSize], bool svoboda[MaxSize])
{
	int count = 0;
	int k = m - 1;
	while (a[k][n - 2] == 0)
	{
		k--;
	}
	int l = n - 2;
	for (int i = k; i >= 0; i--)
	{
		Fraction x = 0;
		if (svoboda[l] == true)
		{
			solut[l] = 0;
			l--;
			i++;
		}
		else
		{
			for (int j = l + 1; j <= n - 2; j++)
				x = x + a[i][j] * solut[j];
			x = a[i][n - 1] - x;
			solut[l] = x / a[i][l];
			l--;
		}
	}

}

int Find_Basis(Fraction a[MaxSize][MaxSize], int m, int n, bool svoboda[MaxSize], Fraction res[MaxSize][MaxSize])
{
	int BigCount = 0;

	for (int q = 0; q < m; q++)
		a[q][n - 1] = 0;

	for (int q = 0; q < n - 1; q++)
	if (svoboda[q] == false)
		continue;
	else
	{
		int count = 0;
		int k = m - 1;
		int l = n - 2;
		while (a[k][n - 2] == 0)
			k--;

		for (int i = k; i >= 0; i--)
		{
			Fraction x = 0;
			if (svoboda[l] == true)
			{
				res[BigCount + 1][l] = 0;
				if (l == q) 
					res[BigCount + 1][l] = 1;
				l--;  
				i++;
			}
			else
			{
				for (int j = l + 1; j <= n - 2; j++)
					x = x + a[i][j] * res[BigCount + 1][j];
				x = a[i][n - 1] - x;
				res[BigCount + 1][l] = x / a[i][l];
				l--;
			}
		}

		if (q == 0)
			res[BigCount + 1][q] = 1;
		BigCount++;
	}

	return BigCount;
}

void gauss(Fraction a[MaxSize][MaxSize], int m, int n, Fraction res[MaxSize][MaxSize], int &m_rows)
{
	Make_Triangle(a, m, n);
	bool bol = Exist_Solut(a, m, n);
	if (bol)
	{
		Fraction solut[MaxSize] = { 0 };
		bool svoboda[MaxSize] = { false };
		Find_Svoboda(a, m, n, svoboda);
		Partial_Solution(a, m, n, solut, svoboda);
		Fraction Basis[MaxSize][MaxSize] = { 0 };
		int BigCount = Find_Basis(a, m, n, svoboda, res);
		for (int p = 0; p < n - 1; p++)
			res[0][p] = solut[p];
		m_rows = BigCount;
	}
	else
	{
		m_rows = -1;
	}
}

bool test_gauss(const char *in_name, const char *out_name)
{

	int m, n, m1, n1;
	Fraction a[MaxSize][MaxSize];
	Fraction res[MaxSize][MaxSize] = { 0 };
	double res1[MaxSize][MaxSize] = { 0 };
	int m_rows;

	read_matr(a, m, n, in_name);

	read_matr(res1, m1, n1, out_name);

	gauss(a, m, n, res, m_rows);
	 //n = n - 1;
	m_rows++;

	if (m1 != m_rows) {
		return false;
		
	}
	for (int i = 0; i < m_rows; i++)
	for (int j = 0; j < n; j++)
	
	if (abs(res[i][j].getValue() - res1[i][j]) > 0.0001 ) {
	
		cout << i << " " << j;
		write_matr(res, ++m_rows, n);
		write_matr(res1, m1, n1);


		return false;
	}
	return true;
}

int main()
{
	int x;
	
	if (test_gauss("C:\\files\\input.txt", "C:\\files\\output.txt"))
		cout << "true 1" << endl;
	else cout << "false 1" << endl;
	if (test_gauss("C:\\files\\input2.txt", "C:\\files\\output2.txt"))
		cout << "true 2" << endl;
	else cout << "false 2" << endl;
	if (test_gauss("C:\\files\\input3.txt", "C:\\files\\output3.txt"))
		cout << "true 3" << endl;
	else cout << "false 3" << endl;
	if (test_gauss("C:\\files\\input4.txt", "C:\\files\\output4.txt"))
		cout << "true 4" << endl;
	else cout << "false 4" << endl;
	if (test_gauss("C:\\files\\input5.txt", "C:\\files\\output5.txt"))
		cout << "true 5" << endl;
	else cout << "false 5" << endl;
	if (test_gauss("C:\\files\\input6.txt", "C:\\files\\output6.txt"))
		cout << "true 6" << endl;
	else cout << "false 6" << endl;
	if (test_gauss("C:\\files\\input7.txt", "C:\\files\\output7.txt"))
		cout << "true 7" << endl;
	else cout << "false 7" << endl;
	cin >> x;
	return 0;
}