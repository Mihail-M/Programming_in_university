
#include "bubblesorter.h"
#include <iostream>


BubbleSorter::BubbleSorter(int *Array)
{
    array = Array;
}

int *BubbleSorter::getSortArray(int l, int r)
{
    sort(l, r);
    return array;
}

int *BubbleSorter::getSortArray(int l, int r, bool (*comp)(int, int))
{
    sort(l, r, comp);
    return array;
}
void swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}

void BubbleSorter::sort(int l, int r)
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

void BubbleSorter::sort(int l, int r, bool (*comp)(int, int))
{
    bool swapped = true;
        int i = 0;
        int n = r - l + 1;
        while(swapped)
        {
            swapped = false;
            i++;
            for(int j = 0; j < n - i; j++)
                if( (*comp)(array[j], array[j+1]))
                {
                    swap(array[j], array[j+1]);
                    swapped = true;
                }
        }
}


