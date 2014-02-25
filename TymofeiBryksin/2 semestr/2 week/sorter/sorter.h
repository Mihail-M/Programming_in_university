#pragma once

class Sorter
{
public:
    Sorter(int *A);
    virtual ~Sorter();

    int *getSortArray(int l, int r);
    int *getSortArray(int l, int r, bool (*comp)(int, int));

protected:
    int *array;
    virtual void sort(int l, int r) = 0;
    virtual void sort(int l, int r, bool (*comp)(int, int) ) = 0;
    void swap(int &a, int &b);

};


