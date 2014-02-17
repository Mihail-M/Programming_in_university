#include <iostream>

using namespace std;

double &f()
{

    static double a = 0, b = 0, c = 0 , r = 0 , r1 = r;

    if (r1 != r)
    {
        b = c;
        c = a;
        a = r;
        r = (a + b + c) / 3;
    }
    r1 = r;
    return r;
}

int main()
{
    cout << f() << ", ";
    f() = 23;
    f() = 12;
    cout << f() << ", ";
    cout << f() << ", ";
    f() = 2;
    f() = -5;
    cout << f() << '.';

    return 0;
}
