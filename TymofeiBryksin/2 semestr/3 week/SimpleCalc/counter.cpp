#include "counter.h"


double Counter::calculate(double a, double b, char operand)
{
    switch(operand) {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a*b;
        break;
    case '/':
        return a/b;
        break;
    }
}
