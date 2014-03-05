#pragma once
#include "sorter.h"

class BubbleSorter : public Sorter
{
public:
      ~BubbleSorter();
      ///sort array
      void sort(int **array, int l, int r);
      ///sort array with comparator
      void sort(int **array, int l, int r, bool (*comp)(int*, int*) );
private:
      ///swap 2 elements
      void swap(int *&a, int *&b);
};
