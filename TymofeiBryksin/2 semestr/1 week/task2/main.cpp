#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <locale>
#include "stack.h"

using namespace std;

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
double calculate(char input[])
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

int main()
{
    char inputStr[10000];
    char queueOut[10000];
    int counter = 0;
    Stack *stack = new Stack();
    printf("This beutiful calc calculate arithmetic expression\n");
    printf("Please enter arithmetic expression\n");
    scanf("%s", inputStr);
    for (int i = 0; i < strlen(inputStr); i++) {

        if ( isdigit(inputStr[i]) )
            queueOut[counter++] = inputStr[i];

        if (isOperator(inputStr[i])) {
            while (isDoINeedToGet(inputStr[i], stack->top()) && !stack->isEmpty()){
                queueOut[counter++] =  (char)stack->top();
                stack->pop();
            }

        stack->push(inputStr[i]);
        }

        if (inputStr[i] == '(')
            stack->push(inputStr[i]);

        if (inputStr[i] == ')') {
            while (stack->top() != '(')
                queueOut[counter++] = (char)stack->top();
            stack->pop();

            if((char)stack->top() == '(' )
                stack->pop();
            else printf("WRONG, WRONG, WRONG! You cheated me!\n");
        }
    }

    while(!stack->isEmpty()){
        queueOut[counter++] =  (char)stack->top();
                   stack->pop();
}
    queueOut[counter++] = '\0';

    printf("Answer is: %.3f\n\nBY BY=)", calculate(queueOut));

    return 0;
}
