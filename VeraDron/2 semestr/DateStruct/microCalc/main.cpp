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
enum operand{ ADDITION = -1, SUBTRACT = -2, MULTIPLICATION = -3, DIVISION = -4 };

double calculate(double *input, int n)
{

    StackPointer calc;
    for (int i = 0; i < n; i++) {
        if (input[i] >= 0)
            calc.push(input[i]);
        else {
            double second = calc.pop();
            double first = calc.pop();
            operand key = static_cast<operand>(input[i]);

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
    }
    double result = calc.top();
    return result;
}
int main(int argc, char *argv[])
{
    double *input = new double[argc-1];

    for(int i = 1; i < argc; i++) {
        if(isdigit(argv[i][0]))
            input[i-1] = toDouble(argv[i]);
        else {
            if(argv[i][0] == '+')
                input[i-1] = -1;
            if(argv[i][0] == '-')
                input[i-1] = -2;
            if(argv[i][0] == '*')
                input[i-1] = -3;
            if(argv[i][0] == '/')
                input[i-1] = -4;
        }
    }

    cout << calculate(input, argc - 1) << endl;
    return 0;
}

