#pragma once
#include "sorter.h"

class BubbleSorter// : public Sorter
{
public:
      BubbleSorter(int *Array);
      int *getSortArray(int l, int r);
      int *getSortArray(int l, int r, bool (*comp)(int, int));
private:
      void sort(int l, int r);
      void sort(int l, int r, bool (*comp)(int, int) );
      int *array;

};

