#include <iostream>

using namespace std;

class A {
public:
	A(double p1, double p2) {
		a = max(p1, p2);
		b = min(p1, p2);
	}

	double add(double x) {
		if (a >= x && b < x)
			b = x;
		else
			if (a < x){
				swap(a,x);
				swap(b, x);
			}
		return x;
	}

	void print() {
		cout << a << " " << b << " ";
	}

private:
	double a, b;
};


class B: public A {
public:
	B(double a1, double b1, double c1): A(a1, b1) {
		c = c1;
	}

	double add(int x) {
		A::add(x);
		if ( x >= c) {
			double temp = c;
			c = A::add(x);
			return temp;
		}
		else return x;
	}
	void print() {
		A::print();
		cout << c << " ";
	}

private:
	int c;
};

int main()
{
	A a(1, 2);
	B b(3, 2, 1);
	a.print();
	cout << endl;
	b.print();
	cout << endl;
	a.add(5);
	a.print();
	cout << endl;
	return 0;
}

