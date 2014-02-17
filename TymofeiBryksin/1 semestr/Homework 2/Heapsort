#include <iostream>

using namespace std;

const int sizeArr = 10000;

struct heap
{
    int value[sizeArr];
    int length = 0;
    void heapify(int root)
    {
        int left = 2 * root + 1;
        int right = 2 * root + 2;
        int largest  = root;

        if (left <= length && value[left] > value[largest ])
            root = left;

        if (right <= length && value[right] > value[largest ])
            root = right;

        if (largest != root)
        {
            swap(value[root], value[largest]);
            heapify(largest);
        }
    }

    void buildHeap(int len)
    {
        length = len;
        for (int i = length / 2; i >= 0; i--)
            heapify(i);
    }

    void del(int n)
    {
        swap(value[n], value[length--]);
        heapify(n);
    }

    void heapsort(int (&answer)[sizeArr])
    {
        while (length)
        {
            answer[length] = value[0];
            del(0);
        }
    }

};

int main()
{
    cout << "This program sorts the array descending with algorithm Heapsort\n";
    int n = 0;
    cout << "Input size of your array: ";
    cin >> n;

    heap arr;
    int answer[sizeArr];
    cout << "Input array: ";

    for (int i = 0; i < n; i++)
        cin >> arr.value[i];

    arr.buildHeap(n);
    arr.heapsort(answer);

    cout << "Answer: ";

    for (int i = 1; i <= n; i++)
        cout << answer[i] << " ";

    return 0;
}
