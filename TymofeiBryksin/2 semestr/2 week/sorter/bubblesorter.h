#pragma once
#include "sorter.h"

///sort with bubble sort(n^2)
class BubbleSorter : public Sorter
{
public:
      ~BubbleSorter();
      ///sort array with bubble sort
      void sort(int *array, int l, int r);
      ///sort array with bubble sort and comparator
      void sort(int *array, int l, int r, bool (*comp)(int, int) );
};
