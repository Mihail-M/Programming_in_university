#include <iostream>

using namespace std;

template <class T>
void bubbleSort(T *array, int n)
{
    bool swapped = true;
    int i = 0;
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

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    bubbleSort(arr, n);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    delete[] arr;
    return 0;
}
