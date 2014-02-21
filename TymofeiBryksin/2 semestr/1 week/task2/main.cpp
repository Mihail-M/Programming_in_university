#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <locale>
#include "stack.h"
#include <iostream>

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
    Stack *stack = new Stack();

    for (int i = 0; i < strlen(inputStr); i++) {

        if ( isdigit(inputStr[i]) )
            queueOut[counter++] = inputStr[i];

        if (isOperator(inputStr[i])) {
            while (!stack->isEmpty() && isOperator(stack->top()) && (priority(inputStr[i]) <= priority(stack->top()))){
                queueOut[counter++] = (char)stack->top();
                stack->pop();
            }

            stack->push(inputStr[i]);
        }

        if (inputStr[i] == '(')
            stack->push(inputStr[i]);

        if (inputStr[i] == ')') {
            while (!stack->isEmpty() && stack->top() != '('){
                queueOut[counter++] = (char)stack->top();
                stack->pop();

                if((char)stack->top() == '(' )
                    stack->pop();
            }
        }
    }

    while(!stack->isEmpty()){
        queueOut[counter++] =  (char)stack->top();
        stack->pop();
    }
    queueOut[counter++] = '\0';

}


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
