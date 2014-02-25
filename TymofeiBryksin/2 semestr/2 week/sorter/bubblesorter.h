#pragma once
#include "sorter.h"

class BubbleSorter : public Sorter
{
public:
      BubbleSorter(int *Array);
      ~BubbleSorter();

private:
      void sort(int l, int r);
      void sort(int l, int r, bool (*comp)(int, int) );
};
