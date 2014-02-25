#include "quicksorter.h"
#include <ctime>
#include <cstdlib>

QuickSorter::QuickSorter(int *Array):Sorter(Array)
{
    array = Array;
}

QuickSorter::~QuickSorter()
{

}



void QuickSorter::sort(int l, int r)
{
    int x, i, j;
    i = l;
    j = r;
    x = array[rand() % (r + 1)];
    while (i <= j)
    {
        while (array[i] < x)
            i++;

        while (array[j] > x)
            j--;

        if (i <= j)
        {
            swap(array[i], array[j]);
            i++;
            j--;
        }
    }

    if (l < j)
        sort(l, j);

    if (i < r)
        sort(i, r);
}

void QuickSorter::sort(int l, int r, bool (*comp)(int, int))
{
    int x, i, j;
    i = l;
    j = r;
    x = array[rand() % (r + 1)];
    while (i <= j)
    {
        while (array[i] < x)
            i++;

        while (array[j] > x)
            j--;

        if ((*comp)(array[j], array[j+1]))
        {
            swap(array[i], array[j]);
            i++;
            j--;
        }
    }

    if (l < j)
        sort(l, j);

    if (i < r)
        sort(i, r);
}



