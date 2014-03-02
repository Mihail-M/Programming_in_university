#pragma once

class Sorter
{
public:
    Sorter();
    virtual ~Sorter();
    virtual void sort(int *array, int l, int r) = 0;
    virtual void sort(int *array, int l, int r, bool (*comp)(int, int) ) = 0;

protected:
    void swap(int &a, int &b);

};


