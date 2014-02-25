#include "sorter.h"

Sorter::Sorter(int *A)
{
    array = A;
}

Sorter::~Sorter()
{
}

int *Sorter::getSortArray(int l, int r)
{
    sort(l, r);
    return array;

}

int *Sorter::getSortArray(int l, int r, bool (*comp)(int, int))
{
    sort(l, r, comp);
    return array;
}

void Sorter::swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}

