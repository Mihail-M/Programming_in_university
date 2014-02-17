#include <iostream>;
#include <fstream>;
#include <cstdio>;
#include <cstdlib>;

using namespace std;


int arr[1000][1000];
int n, m;
void search(int &x,int &y, int key)
{
    if(x == m || y < 0)
        return;

    if(key > arr[x][y])
        search(++x, y, key);
    else if (key < arr[x][y])
        search(x, --y, key);
    else if (key == arr[x][y])
        return;
}

int main()
{
    cin >> m >> n;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];

    int key = 0;
    cin >> key;
    int x = 0;
    int y = n - 1;
    search(x, y, key);
    if(arr[x][y]!=key)
        cout << -1;
    else
        cout << x+1 << " " << y+1;
}
