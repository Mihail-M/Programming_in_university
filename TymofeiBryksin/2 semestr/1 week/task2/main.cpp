#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <locale>
#include "stack.h"
#include <iostream>
#include "stackarr.h"

using namespace std;

bool isOperator(char a)
{
    return a == '+' || a == '-' || a == '*' || a == '/';
}

bool isStaple(char a)
{
    return a == '(' || a == ')';
}
int priority(char c)
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
void makePolishNotation(char *inputStr, char *queueOut) {
    int counter = 0;
    stack *st = new stack();

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
}


double calculate(char *input)
{

    stack calc;
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

int main()
{
    char inputStr[10000];
    char queueOut[10000];

    printf("This beutiful calc calculate arithmetic expression\n");
    printf("Please enter arithmetic expression\n");
    scanf("%s", inputStr);
    makePolishNotation(inputStr, queueOut);

    printf("Answer is: %.7f\n\nBY BY=)", calculate(queueOut));

    return 0;
}
