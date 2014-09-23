#include <iostream>

using namespace std;

const int inf=1000067,maxn=1000;

int a[maxn][maxn], d[maxn], p[maxn], n, s, f;
bool use[maxn];

void djkstra(int s)
{
    int jmin, mind;
    for(int i = 0; i < n; i++)
    {
        d[i] = inf;
        use[i] = false;
        p[i] = i;
    }

    d[s] = 0;
    for (int i = 0; i < n; i++) //cout<<i<<" ";
    {
        mind = inf;
        for(int j = 0; j < n; j++)
        {
            if( (!use[j]) && (mind > d[j]))  //cout<<j<<" ";
            {
                jmin = j;
                mind = d[j];
            }
        }
        if (mind == inf)
            break;

        use[jmin] = true;

        for(int j = 0; j < n; j++)
        {
            if ( (a[jmin][j] != -1) && (d[j] > d[jmin] + a[jmin][j]))
            {
                d[j] = d[jmin] + a[jmin][j];
                p[j] = jmin;
            }
        }
    }
}


void path(int f)
{
    if (s - 1 != f)
    {
        path(p[f]);
        cout << f + 1<<" ";
    }
}
int main()
{
    cin >> n >> s >> f;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    djkstra(s-1);
    if (d[f-1] != inf)
    {
        cout << d[f - 1] << endl;
        cout << s << " ";
        path(f - 1);

        return 0;
    }

    cout << -1;
    return 0;
}



