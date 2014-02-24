#pragma once

class Sorter
{
public:

    Sorter(int *Array);
    virtual ~Sorter();

    virtual void sort(int *arr, int l, int r) ;
    virtual void sort(int *arr, bool (*comp)(int, int) );
    virtual int *getSortArray(int l, int r);
    virtual int *getSortArray(int l, int r, bool (*comp)(int, int));

protected:
    int *array;
};

