#include "mergesorter.h"


MergeSorter::MergeSorter(int *Array):Sorter(Array)
{
}

MergeSorter::~MergeSorter()
{

}

void MergeSorter::sort(int l, int r)
{
    int m = (l + r) / 2;

    if(l<r) {
        sort(l, m);
        sort(m + 1, r);
        merge(l, m, r);
    }
}

void MergeSorter::sort(int l, int r, bool (*comp)(int, int))
{
    int m = (l + r) / 2;

    if(l<r) {
        sort(l, m, comp);
        sort(m + 1, r, comp);
        merge(l, m, r, comp);
    }
}

void MergeSorter::merge(int l, int m, int r)
{
    int i = l, j = m + 1, pres = 0;
       int *b = new int[r - l + 1];

       while (i <= m && j <= r)
           if (array[i] < array[j])
               b[pres++] = array[i++];
           else
               b[pres++] = array[j++];

       while (i<=m)
           b[pres++] = array[i++];

       while (j<=r)
           b[pres++] = array[j++];

       for (int k = l; k <= r; k++)
           array[k] = b[k - l];
       delete[] b;
}

void MergeSorter::merge(int l, int m, int r, bool (*comp)(int, int))
{
    int i = l, j = m + 1, pres = 0;
       int *b = new int[r - l + 1];

       while (i <= m && j <= r)
           if ((*comp)(array[i], array[j]))
               b[pres++] = array[i++];
           else
               b[pres++] = array[j++];

       while (i<=m)
           b[pres++] = array[i++];

       while (j<=r)
           b[pres++] = array[j++];

       for (int k = l; k <= r; k++)
           array[k] = b[k - l];

       delete[] b;
}