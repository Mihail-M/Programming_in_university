#include <iostream>
#include <vector>
#include <complex>
#include <cmath>

using namespace std;

void FFT (vector<complex<double> > & a, bool invert) {
	int n = a.size();
	if (n == 1)
        return;

	vector<complex<double> > a0 (n/2),  a1 (n/2);

	for (int i=0, j=0; i<n; i+=2, ++j) {
		a0[j] = a[i];
		a1[j] = a[i+1];
	}

	FFT(a0, invert);
	FFT(a1, invert);

	double f = 2 * M_PI / n * (invert ? -1 : 1);

	complex<double> w (1),  wn (cos(f), sin(f));
	for (int i=0; i<n/2; ++i) {
		a[i] = a0[i] + w * a1[i];
		a[i + n/2] = a0[i] - w * a1[i];
		if (invert){
			a[i] /= 2;
            a[i+n/2] /= 2;
            }
		w *= wn;
	}
}

void multiply (const vector<int> & a, const vector<int> & b, vector<int> & res) {

	vector<complex<double> > fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	size_t n = 1;
	while (n < max (a.size(), b.size()))  n *= 2;

	n *= 2;

	fa.resize (n),  fb.resize (n);

	FFT(fa, false);
    FFT (fb, false);

	for (int i = 0; i < n; i++)
		fa[i] *= fb[i];

	FFT (fa, true);

    res.resize(n);
	for (size_t i=0; i<n; ++i)
		res[i] = int (real(fa[i]) + 0.5);

}

void shiftForCharacter(char G, string &a, string &b, vector <int> &shift) {
    vector <int> A, B;
    int N = a.size();
    for (int i = 0; i < a.size(); i++) {
            if (a[i] == G)
                A.push_back(1);
            else A.push_back(0);
    }
    for (int i = b.size() - 1; i >= 0; i--) {
            if (b[i] == G)
                B.push_back(1);
            else B.push_back(0);
    }
    vector <int> C;
    multiply(A, B, C);
	shift[0] += C[N - 1];

	for (int i = 0; i < N - 1; i++)
		shift[i + 1] += C[i] + C[i + N];
}

int main()
{
    int n;
    cin >> n;
    string A,B;
    cin >> A >> B;
    vector<int> shift(n+1);
    shiftForCharacter('A', A, B, shift);
    shiftForCharacter('T', A, B, shift);
    shiftForCharacter('C', A, B, shift);
    shiftForCharacter('G', A, B, shift);

    int max = 0;

    for (int i = 0; i < n; i++)
		if (shift[i] > shift[max])
			max =  i;

	cout << shift[max] << ' ' << max << endl;

    return 0;
}
