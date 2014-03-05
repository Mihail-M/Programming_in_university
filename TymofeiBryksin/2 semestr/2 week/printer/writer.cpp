#include "writer.h"


Writer::~Writer()
{

}


int *Writer::getAns(int n, int **array)
{
    int *ans = new int[n * n];

    int centerPosition = n / 2;
    int deviation = 0;
    int counter = 0;
    ans[counter++] = array[centerPosition][centerPosition];

    for (int r = 0; r <= n - 3; r += 2)
    {
        if (!r)
            getNext(array, centerPosition,centerPosition+1, 2, ans, counter);
        else
        {
            deviation++;
            getNext(array, centerPosition + deviation,centerPosition + deviation + 1, r + 2, ans, counter);
        }
    }
    return ans;
}

void Writer::getNext(int **array, int x, int y, int r, int *ans, int &counter)
{
    for (int ix = 0; ix < r; ix++)
            ans[counter++] = array[x - ix][y];

        x -= r - 1;
        y -= 1;

        for (int iy = 0; iy < r; iy++)
            ans[counter++] = array[x][y - iy];

        y -= r - 1;

        for (int ix = 0; ix < r; ix++)
            ans[counter++] = array[x + ix + 1][y];

        x += r;

        for (int iy = 0; iy < r; iy++)
            ans[counter++] = array[x][y + iy + 1];
}

