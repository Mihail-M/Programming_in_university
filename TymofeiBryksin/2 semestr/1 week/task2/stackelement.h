#pragma once

typedef double valueType;

class StackElement
{
public:
    StackElement();

    valueType getKey() const;
    void setKey(const valueType &value);

    StackElement *getPrev() const;
    void setPrev(StackElement *value);

private:
    valueType key;
    StackElement *prev;

};
