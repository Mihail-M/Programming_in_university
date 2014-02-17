#pragma once

namespace Stacks
{
    struct StackElement
    {
        StackElement* next;
        char value;

    };

    struct Stack
    {
        StackElement* head;
        int size;
    };

    bool isEmpty(Stack *stack);
    Stack* create();
    void push(Stack *stack, char value);
    char pop(Stack *stack);
    char front(Stack *stack);
    void deleteStack(Stack *stack);

}
