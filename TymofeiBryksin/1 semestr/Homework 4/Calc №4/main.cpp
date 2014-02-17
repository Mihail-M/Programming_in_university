#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <locale>
#include "Stack.h"

using namespace std;
using namespace Stacks;

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

    Stack *calc = create();
    for (int i = 0; i < strlen(input); i++)
        if(isdigit(input[i]))
            push(calc, input[i] - '0');
        else {
            switch (input[i]) {
            case '*':
                push(calc, pop(calc) * pop(calc));
                break;
            case '/':
                push(calc, pop(calc) / pop(calc));
                break;
            case '+':
                push(calc, pop(calc) + pop(calc));
                break;
            case '-':
                push(calc, pop(calc) - pop(calc));
                break;

            default:
                printf("Sorry(\n");
                break;
            }
        }
    double result = pop(calc);
    deleteStack(calc);
    return result;
}

int main()
{
    char inputStr[10000];
    char queueOut[10000];
    int counter = 0;
    Stack *stack = create();
    printf("This beutiful calc calculate arithmetic expression\n");
    printf("Please enter arithmetic expression\n");
    scanf("%s", inputStr);
    for (int i = 0; i < strlen(inputStr); i++) {

        if ( isdigit(inputStr[i]) )
            queueOut[counter++] = inputStr[i];

        if (isOperator(inputStr[i])) {
            while (isDoINeedToGet(inputStr[i], front(stack)) && !isEmpty(stack)){
                queueOut[counter++] =  (char)front(stack);
                pop(stack);
            }

        push(stack, inputStr[i]);
        }

        if (inputStr[i] == '(')
            push(stack, inputStr[i]);

        if (inputStr[i] == ')') {
            while (front(stack) != '(')
                queueOut[counter++] = (char)pop(stack);

            if((char)front(stack) == '(' )
                pop(stack);
            else printf("WRONG, WRONG, WRONG! You cheated me!\n");
        }
    }

    while(!isEmpty(stack))
        queueOut[counter++] =  (char)pop(stack);

    queueOut[counter++] = '\0';

    printf("Answer is: %.3f\n\nBY BY=)", calculate(queueOut));

    deleteStack(stack);
    return 0;
}

