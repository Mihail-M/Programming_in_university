#pragma once
#include "sorter.h"

class QuickSorter : public Sorter
{
public:
    QuickSorter(int *Array);
    ~QuickSorter();

private:
    void sort(int l, int r);
    void sort(int l, int r, bool (*comp)(int, int) );

};

