#include "calc.h"
#include "stack.h"
#include <cstring>
#include <iostream>

Calc::Calc()
{
}

double Calc::calculate(char *input)
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
    double result = calc->top();
    return result;
}

bool isOperator(char a)
{
    return a == '+' || a == '-' || a == '*' || a == '/';
}
bool isLowPriorityOperator(char a)
{
    return a == '+' ||  a =='-';
}

bool isHightPriorityOperator(char a)
{
    return a == '*' ||  a =='/';
}

bool isStaple(char a)
{
    return a == '(' || a == '-';
}
bool isDoINeedToGet(char a, char b)
{
    return ( (isLowPriorityOperator(a) && isHightPriorityOperator(b)) || (isLowPriorityOperator(a) && isHightPriorityOperator(b)) );
}

