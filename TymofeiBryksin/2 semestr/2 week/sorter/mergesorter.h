#pragma once
#include <sorter.h>

class MergeSorter : public Sorter
{
public:
    MergeSorter();
    ~MergeSorter();
    void sort(int *array, int l, int r);
    void sort(int *array, int l, int r, bool (*comp)(int, int) );
private:
    void merge(int *array, int l, int m, int r);
    void merge(int *array, int l, int m, int r, bool (*comp)(int, int));

};

