#include <iostream>

using namespace std;

class A {
public:
     A(double _x1, double _x2):a(max(_x1,_x2)), b(min(_x1,_x2)) {}
     double show(double x) {
        double ans = min(x, b);
		b = min(max(b, x), max(a, b));
		a = max(a, x);
		return ans;
    }
    void print() {
        cout << a << " " << b << " ";
    }

private:
    double a, b;
};

class B: public A{
public:
    B(double _x1, double _x2, double _x3): A(_x1, _x2), c(A::show(_x3)) {}
    double show(double x) {
        c = A::show(x);
        return c;
    }
    void print() {
        A::print();
        cout << c << " ";
    }
private:
    double c;
};

int main()
{
    A a(2, 3);
    B b(2, 3, 4);
    a.print();


    b.show(5);
    b.show(8);
    b.show(2);
    b.print();
    return 0;
}
