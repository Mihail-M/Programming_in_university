#pragma once

class Sorter
{
public:
    Sorter(int *A){
        array = A;
    }

    virtual int *getSortArray(int l, int r) = 0;
    virtual int *getSortArray(int l, int r, bool (*comp)(int, int)) = 0;

protected:
    int *array;
    virtual void sort(int *arr, int l, int r) = 0 ;
    virtual void sort(int *arr, bool (*comp)(int, int) ) = 0;


};

