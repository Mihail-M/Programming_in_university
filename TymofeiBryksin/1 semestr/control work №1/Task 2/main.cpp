#include <iostream>
#include "Stack.h"
#include <cstring>

using namespace std;
using namespace Stacks;

bool isOpen(char c)
{
    return c == '(' || c == '{' || c == '[';
}

bool isSameType(char a, char b)
{
    return (a == '[' && b == '{') || (a == '{' && b == '}') || (a == '(' && b==')');
}

int main()
{
    char inputStr[10000];
    cout << "Hi dear Vasya. I learned about vtoey trouble and decided to help.\n";
    cout << "This program will automatically check the validity of your text.\n";
    cout << "Just input your text: ";
    cin >> inputStr;

    Stack *stack = create();

    for(int i = 0; i < strlen(inputStr); i++)
    {
        if(isalpha(inputStr[i]))
            continue;

        if (isOpen(inputStr[i]))
            push(stack, inputStr[i]);
        else
        {

            if(!isEmpty(stack) && isSameType(front(stack), inputStr[i]) )
                pop(stack);
            else
            {
                push(stack, inputStr[i]);
            }

        }
    }

    if (stack->size == 0)
        cout << "This text is correct";
    else
        cout << "This text is not correct!!";
    deleteStack(stack);
    return 0;
}

