#pragma once
#include <sorter.h>


///sort with merge sort(n*log(n))
class MergeSorter : public Sorter
{
public:
    ~MergeSorter();

    ///sort array with merge sort
    void sort(int *array, int l, int r);
    ///sort array with merge sort and comparator
    void sort(int *array, int l, int r, bool (*comp)(int, int) );

private:
    ///Merge
    void merge(int *array, int l, int m, int r);
    ///Merge with comparator
    void merge(int *array, int l, int m, int r, bool (*comp)(int, int));

};

