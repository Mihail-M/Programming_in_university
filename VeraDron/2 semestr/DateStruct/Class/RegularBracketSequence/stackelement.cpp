#include "stackelement.h"

StackElement::StackElement()
{
}
valueType StackElement::getKey() const
{
    return key;
}

void StackElement::setKey(const valueType &value)
{
    key = value;
}
StackElement *StackElement::getPrev() const
{
    return prev;
}

void StackElement::setPrev(StackElement *value)
{
    prev = value;
}

