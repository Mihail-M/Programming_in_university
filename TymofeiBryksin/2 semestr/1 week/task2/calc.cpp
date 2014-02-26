#include "calc.h"
#include "stackpointer.h"
#include <cstdio>
#include <cstring>
#include <locale>

Calc::Calc()
{
}

bool Calc::isOperator(char a)
{
    return a == '+' || a == '-' || a == '*' || a == '/';
}

bool Calc::isStaple(char a)
{
    return a == '(' || a == ')';
}

int Calc::priority(char c)
{
    switch(c)
    {
    case '*': return 3;
    case '/': return 3;

    case '+': return 2;
    case '-': return 2;
    }
    return 0;
}

void Calc::makePolishNotation(char *inputStr, char *queueOut) {
    int counter = 0;
    StackPointer *st = new StackPointer();

    for (int i = 0; i < strlen(inputStr); i++) {

        if ( isdigit(inputStr[i]) )
            queueOut[counter++] = inputStr[i];

        if (isOperator(inputStr[i])) {
            while (!st->isEmpty() && isOperator(st->top()) && (priority(inputStr[i]) <= priority(st->top()))){
                queueOut[counter++] = (char)st->top();
                st->pop();
            }

            st->push(inputStr[i]);
        }

        if (inputStr[i] == '(')
            st->push(inputStr[i]);

        if (inputStr[i] == ')') {
            while (!st->isEmpty() && st->top() != '('){
                queueOut[counter++] = (char)st->top();
                st->pop();

                if((char)st->top() == '(' )
                    st->pop();
            }
        }
    }

    while(!st->isEmpty()){
        queueOut[counter++] =  (char)st->top();
        st->pop();
    }
    queueOut[counter++] = '\0';
    delete st;
}


double Calc::calculate(char *input)
{
    StackPointer calc;
    makePolishNotation(input, input);

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
