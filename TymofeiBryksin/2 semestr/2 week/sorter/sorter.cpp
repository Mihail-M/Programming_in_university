#include "sorter.h"

Sorter::Sorter()
{
}

Sorter::~Sorter()
{
}


void Sorter::swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}

