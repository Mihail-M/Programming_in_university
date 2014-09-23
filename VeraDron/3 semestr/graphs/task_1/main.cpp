#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n;
pair <int, int> point1, point2;

int dx[] = {2, 2, 1, 1,-1,-1,-2,-2};
int dy[] = {1,-1, 2,-2, 2,-2, 1,-1};
int used[50][50];
int d[50][50];
pair <int, int> p[50][50];

bool check(int x1, int y1)
{
    if (x1 < n && x1 >= 0 && y1 < n && y1 >= 0)
        return true;
    return false;
}

int main()
{
    cin >> n;
    cin >> point1.first >> point1.second >> point2.first >> point2.second;

    queue < pair <int, int> > q;
    point1.first--;
    point1.second--;

    d[point1.first][point2.second] = 0;
    p[point1.first][point1.second] = make_pair(-1, -1);

    point2.second--;
    point2.first--;

    q.push(point1);
    used[point1.first][point1.second] = 1;

    pair <int, int> temp = point1;
    while (!q.empty())
    {
        for (int i = 0; i < 8; i++)
            if (check(temp.first + dx[i], temp.second + dy[i]) && !used[temp.first + dx[i]][temp.second + dy[i]])
            {
                q.push(make_pair(temp.first + dx[i], temp.second + dy[i]));
                p[temp.first + dx[i]][temp.second + dy[i]] = temp;
                d[temp.first + dx[i]][temp.second + dy[i]] = d[temp.first][temp.second] + 1;
                used[temp.first + dx[i]][temp.second + dy[i]] = 1;
            }

        if (temp.first == point2.first && temp.second == point2.second)
        {
            cout << d[point2.first][point2.second] << endl;
            break;
        }

        temp = q.front();
        q.pop();
    }

    vector <pair<int, int> > inp;
    for (pair <int, int> i = point2; i != make_pair(-1, -1); i = p[i.first][i.second])
        inp.push_back(i);

    for(int i = inp.size() - 1; i >= 0; i--)
            cout << inp[i].first + 1 << " " << inp[i].second + 1 << endl;

    return 0;
}
