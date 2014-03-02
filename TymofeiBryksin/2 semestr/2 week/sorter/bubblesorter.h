#pragma once
#include "sorter.h"

class BubbleSorter : public Sorter
{
public:
      BubbleSorter();
      ~BubbleSorter();
      void sort(int *array, int l, int r);
      void sort(int *array, int l, int r, bool (*comp)(int, int) );
};
