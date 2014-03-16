#include <iostream>
#include "teststack.h"
#include "calc.h"
#include "testcalc.h"
using namespace std;

int main()
{
    TestStack a;
    QTest::qExec(&a);
    TestCalc b;
    QTest::qExec(&b);

    char inputStr[10000];
    printf("This beutiful calc calculate arithmetic expression\n");
    printf("Please enter arithmetic expression\n");
    scanf("%s", inputStr);
    Calc calc;

    printf("Answer is: %.7f\n\nBY BY=)", calc.calculate(inputStr));

    return 0;
}
