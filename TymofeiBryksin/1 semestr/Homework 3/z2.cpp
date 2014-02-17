#include <iostream>
#include <cstdlib>
using namespace std;

void print(int x,int y, int r, int block[100][100]) //вывод очередного витка спирали
{

    for (int ix = 0; ix < r; ix++)
        cout<<block[x - ix][y] << " ";
 
    x -= r - 1;
    y -= 1;

    for (int iy = 0; iy < r; iy++)
        cout << block[x][y - iy] << " ";

    y -= r - 1;

    for (int ix = 0; ix < r; ix++)
        cout<<block[x + ix + 1][y]<< " ";

    x += r;

    for (int iy = 0; iy < r; iy++)
        cout << block[x][y + iy + 1] << " ";

}
int main()
{
    int block[100][100];
    int n = 0;

    cout << "Enter the size of the array (odd)" << endl;

    cin >> n;

    int centerPosition = n / 2;
    cout << "Input array: " << endl;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> block[i][j];

    int deviation = 0;

    cout << "Answer is: " << endl;
    cout << block[centerPosition][centerPosition] << " ";

    for (int r = 0; r <= n - 3; r += 2)
    {
        if (!r)
            print(centerPosition,centerPosition+1, 2, block);
        else
        {
            deviation++;
            print(centerPosition + deviation,centerPosition + deviation + 1, r + 2, block);
        }
    }

    return 0;
}

