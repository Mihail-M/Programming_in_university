#include <iostream>
#include <fstream>

#include "treeparse.h"
#include "testtreeparse.h"

using namespace std;

int main()
{
    TestTreeParse test;
    QTest::qExec(&test);

    TreeParse a;
    a.parse(cin);
    a.print();
    cout << endl;
    a.printNormal();
    cout << endl;
    cout << a.calculate();
    return 0;
}
