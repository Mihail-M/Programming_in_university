#include <iostream>
#include "stackpointer.h"
#include <cstring>

using namespace std;

double toDouble(char *a){
    double ans = 0;
    int n = strlen(a);
    int factor = 1;
    for(int i = n-1; i >= 0; i--) {
        ans += (a[i] - '0') * factor;
        factor *= 10;
    }
    return ans;
}
enum operandUser{ ADDITION = '+', SUBTRACT = '-', MULTIPLICATION = '*', DIVISION = '/' };

double calculate(double *input,char *operand, int countNumber, int countOperand)
{

    StackPointer calc;
    for (int i = 0; i < countNumber; i++)
        calc.push(input[i]);

    for(int i = countOperand - 1; i >= 0; i--)
    {
        double second = calc.pop();
        double first = calc.pop();

        operandUser key = static_cast<operandUser>(operand[i]);

        switch (key) {
        case MULTIPLICATION:
            calc.push(first * second);
            break;
        case DIVISION:
            calc.push(first / second);
            break;
        case ADDITION:
            calc.push(first + second);
            break;
        case SUBTRACT:
            calc.push(first - second);
            break;

        default:
            printf("Sorry(\n");
            break;
        }
    }

    double result = calc.top();
    return result;
}

int main(int argc, char *argv[])
{
    double *input = new double[argc-1];
    char *operand = new char[argc-1];

    int iterDouble = 0, iterOper = 0;

    for(int i = 1; i < argc; i++) {
        if(isdigit(argv[i][0]))
            input[iterDouble++] = toDouble(argv[i]);
        else {
            operand[iterOper++] = argv[i][0];
        }
    }

    cout << calculate(input, operand, iterDouble, iterOper) << endl;
    delete[] input;
    delete[] operand;

    return 0;
}

