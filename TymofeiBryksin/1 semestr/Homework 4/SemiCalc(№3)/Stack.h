#pragma once

namespace Stacks
{
    struct StackElement
    {
        StackElement* next;
        double value;

    };

    struct Stack
    {
        StackElement* head;
        int size;
    };

    bool isEmpty(Stack *stack);
    Stack* create();
    void push(Stack *stack, double value);
    double pop(Stack *stack);
    double front(Stack *stack);
    void deleteStack(Stack *stack);

}
