#include <iostream>
#include <algorithm>


using namespace std;
int digit(int a,int k)
{
    for(int i =0 ; i <= k-1; i++)
        a /= 10;
    return a % 10;
}
int countRadix(int a)
{
    int ans  = 0;
    while(a){
        a /= 10;
        ans++;
    }
    return ans;;
}

void radixSort(int *array, int n)
{
    int maxIteration = countRadix(*max_element(array, array + n));
    int **tempArray = new int*[10];
    for(int i = 0; i < 10; i++)
        tempArray[i] = new int[n];

    for(int i = 0 ; i < 10; i++)
        for(int j = 0; j < n; j++)
            tempArray[i][j] = -1;

    int k = 0;
    int pos[10] = {0};
    while(k <= maxIteration)
    {
        for (int i = 0; i < n; i++)
        {
            int digitInd = digit(array[i], k);
            tempArray[digitInd][pos[digitInd]++] = array[i];
        }

        k++;
        int q = 0;

        for(int i = 0; i < 10; i++)
            for(int j = 0 ; j < pos[i]; j++)
                if(tempArray[i][j] != -1)
                    array[q++] =  tempArray[i][j];

        for(int i = 0; i < 10; i++)
        {
            pos[i] = 0;
            for(int j = 0; j < n; j++)
            {
                tempArray[i][j] = -1;
            }
        }
    }

    for(int i = 0; i < 10; i++)
        delete[] tempArray[i];
    delete[] tempArray;
}

int main()
{
    int n;
    cin >> n;
    int *array = new int[n];

    for(int i = 0; i < n; i++)
        cin >> array[i];

    radixSort(array, n);

    for(int i = 0; i < n; i++)
        cout << array[i] << " ";

    delete[] array;
    return 0;
}
