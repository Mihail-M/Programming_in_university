#include <iostream>

using namespace std;

int binpow (int a, int n)
{
	int temp = 1;
	while (n) {
		if (n % 2)
			temp *= a;
		a *= a;
		n /= 2;
	}
	return temp;
}

int main()
{
    int n = 0;
    int power = 0;
    cout << "This program calcululete power\nInput digit and power:";
    cin >> n >> power;

    cout << "Answer: "<<binpow(n, power);

    return 0;
}
