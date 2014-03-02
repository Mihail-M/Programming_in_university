#include <iostream>
#include "bubblesorter.h"


BubbleSorter::BubbleSorter()
{
}

BubbleSorter::~BubbleSorter()
{

}

void BubbleSorter::sort(int *array, int l, int r)
{
    bool swapped = true;
    int i = 0;
    int n = r - l + 1;
    while(swapped)
    {
        swapped = false;
        i++;
        for(int j = 0; j < n - i; j++)
            if( array[j] > array[j+1])
            {
                swap(array[j], array[j+1]);
                swapped = true;
            }
    }
}

void BubbleSorter::sort(int *array, int l, int r, bool (*comp)(int, int))
{
    bool swapped = true;
        int i = 0;
        int n = r - l + 1;
        while(swapped)
        {
            swapped = false;
            i++;
            for(int j = 0; j < n - i; j++)
                if( !(*comp)(array[j], array[j+1]))
                {
                    swap(array[j], array[j+1]);
                    swapped = true;
                }
        }
}


