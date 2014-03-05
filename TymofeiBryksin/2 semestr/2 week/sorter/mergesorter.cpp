#include "mergesorter.h"




MergeSorter::~MergeSorter()
{

}

void MergeSorter::sort(int *array, int l, int r)
{
    int m = (l + r) / 2;

    if (l<r) {
        sort(array, l, m);
        sort(array, m + 1, r);
        merge(array, l, m, r);
    }
}

void MergeSorter::sort(int *array, int l, int r, bool (*comp)(int, int))
{
    int m = (l + r) / 2;

    if (l<r) {
        sort(array, l, m, comp);
        sort(array, m + 1, r, comp);
        merge(array, l, m, r, comp);
    }
}

void MergeSorter::merge(int *array, int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    int pres = 0;

    int *b = new int[r - l + 1];

    while (i <= m && j <= r)
        if (array[i] < array[j])
            b[pres++] = array[i++];
        else
            b[pres++] = array[j++];

    while (i <= m)
        b[pres++] = array[i++];

    while (j <= r)
        b[pres++] = array[j++];

    for (int k = l; k <= r; k++)
        array[k] = b[k - l];
    delete[] b;
}

void MergeSorter::merge(int *array, int l, int m, int r, bool (*comp)(int, int))
{
    int i = l;
    int j = m + 1;
    int pres = 0;

    int *b = new int[r - l + 1];

    while (i <= m && j <= r)
        if ((*comp)(array[i], array[j]))
            b[pres++] = array[i++];
        else
            b[pres++] = array[j++];

    while (i <= m)
        b[pres++] = array[i++];

    while (j <= r)
        b[pres++] = array[j++];

    for (int k = l; k <= r; k++)
        array[k] = b[k - l];

    delete[] b;
}
