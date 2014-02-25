#pragma once

class Sorter
{
public:
    Sorter(int *A);
    virtual ~Sorter();

    virtual int *getSortArray(int l, int r) = 0;
    virtual int *getSortArray(int l, int r, bool (*comp)(int, int)) = 0;

protected:
    int *array;
    virtual void sort(int l, int r) = 0;
    virtual void sort(int l, int r, bool (*comp)(int, int) ) = 0;
};


