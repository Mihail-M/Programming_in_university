#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <locale>
#include "Stack.h"

using namespace std;
using namespace Stacks;

bool isOperator(char a) {
    return a == '+' || a == '-' || a == '*' || a == '/';
}
bool isLowPriorityOperator(char a){
    return a == '+' ||  a =='-';
}

bool isHightPriorityOperator(char a){
    return a == '*' ||  a =='/';
}

bool isStaple(char a) {
    return a == '(' || a == '-';
}
bool isDoINeedToGet(char a, char b){
    return ( (isLowPriorityOperator(a) && isHightPriorityOperator(b)) || (isLowPriorityOperator(a) && isHightPriorityOperator(b)) );
}

int main()
{
    char queueOut[10000];
    char inputStr[10000];
    int counter = 0;
    Stack *stack = create();
    printf("This program using algorithm sort station\n");
    printf("Please enter arithmetic expression\n");
    scanf("%s", inputStr);
    for (int i = 0; i < strlen(inputStr); i++) {

        if ( isdigit(inputStr[i]) )
            queueOut[counter++] = inputStr[i];

        if (isOperator(inputStr[i])) {
            while (isDoINeedToGet(inputStr[i], front(stack)) && !isEmpty(stack)){
                queueOut[counter++] = front(stack);
                pop(stack);
            }

        push(stack, inputStr[i]);
        }

        if (inputStr[i] == '(')
            push(stack, inputStr[i]);

        if (inputStr[i] == ')') {
            while (front(stack) != '(')
                queueOut[counter++] = pop(stack);

            if(front(stack) == '(' )
                pop(stack);
            else printf("WRONG, WRONG, WRONG! You cheated me!\n");
        }
    }

    while(!isEmpty(stack))
        queueOut[counter++] = pop(stack);

    printf("Answer is: ");

    for( int i = 0; i < counter; i++)
        printf("%c ", queueOut[i]);

    printf("\n\n\nBY BY");
    deleteStack(stack);
    return 0;
}
