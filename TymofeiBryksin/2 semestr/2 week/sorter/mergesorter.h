#pragma once
#include <sorter.h>

class MergeSorter : public Sorter
{
public:
    MergeSorter(int *Array);
    ~MergeSorter();

private:
    void sort(int l, int r);
    void sort(int l, int r, bool (*comp)(int, int) );
    void merge(int l, int m, int r);
    void merge(int l, int m, int r, bool (*comp)(int, int));

};

