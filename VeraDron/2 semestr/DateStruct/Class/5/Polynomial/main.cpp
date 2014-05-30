#include <iostream>
#include "polynomial.h"

using namespace std;

int main()
{
    Polynomial a;
    a.set_coef(0, 3);
    a.set_coef(1, 2);
    a.set_coef(3, 1);

    a.print();
    cout << "at x = 3 - " << a.value(3) << endl;
    cout << "at x = 4 - " << a.value(4) << endl;
    Polynomial b;
    b.set_coef(0, 3);
    b.set_coef(1, 2);
    b.set_coef(3, 1);
    b = b*a;
    b.print();


    return 0;
}

