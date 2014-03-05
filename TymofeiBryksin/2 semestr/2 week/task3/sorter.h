#pragma once

class Sorter
{
public:
    virtual ~Sorter();
    ///sort array
    virtual void sort(int **array, int l, int r) = 0;
    ///sort array with comparator
    virtual void sort(int **array, int l, int r, bool (*comp)(int*, int*) ) = 0;
};


