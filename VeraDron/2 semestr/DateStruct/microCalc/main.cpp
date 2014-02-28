#include <iostream>
#include "stack.h"
#include <cstring>

using namespace std;

double calculate(char *input)
{

    Stack calc;
    for (int i = 0; i < strlen(input); i++) {
        if(isdigit(input[i]))
            calc.push(input[i] - '0');
        else {
            double second = calc.pop();
            double first = calc.pop();

            switch (input[i]) {
            case '*':
                calc.push(first * second);
                break;
            case '/':
                calc.push(first / second);
                break;
            case '+':
                calc.push(first + second);
                break;
            case '-':
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
    char *input = new char[argc-1];
    for(int i = 1; i < argc; i++)
        input[i-1] = argv[i][0];

    cout << calculate(input) << endl;
    return 0;
}

