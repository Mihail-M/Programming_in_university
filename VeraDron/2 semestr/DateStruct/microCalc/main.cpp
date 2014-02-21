#include <iostream>
#include "stack.h"
#include <cstring>

using namespace std;

double calculate(char *input)
{
    Stack *calc = new Stack();

    for (int i = 0; i < strlen(input); i++)
        if(isdigit(input[i]))
            calc->push(input[i] - '0');
        else {
            double first = 0, second = 0;
            switch (input[i]) {
            case '*':
                first = calc->top();
                calc->pop();
                second = calc->top();
                calc->pop();
                calc->push(first * second);
                break;
            case '/':
                first = calc->top();
                calc->pop();
                second = calc->top();
                calc->pop();

                calc->push(first / second);
                break;
            case '+':
                first = calc->top();
                calc->pop();
                second = calc->top();
                calc->pop();

                calc->push(first + second);
                break;
            case '-':
                first = calc->top();
                calc->pop();
                second = calc->top();
                calc->pop();

                calc->push(first - second);
                break;

            default:
                break;
            }
        }
    delete calc;
    double result = calc->top();
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

