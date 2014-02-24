#pragma once
typedef double valueType;
class stack
{

public:

    stack();
    ~stack();

    bool isEmpty();

    virtual void push(valueType x);
    virtual valueType pop();
    virtual void clear();
    virtual valueType top();
    int Size();

    valueType getKey() const;
    void setKey(valueType value);

protected:
    int size;

    struct StackElement
    {
        StackElement* prev;
        double key;
    };

    StackElement *last;
};
