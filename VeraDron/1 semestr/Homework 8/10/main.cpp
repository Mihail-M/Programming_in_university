#include <iostream>
#include <algorithm>

using namespace std;
int m[100];
int n;

int Count(int d)
{
    int maxcount = 1;
    for(int k = 0; k < n; k++)
    {
        int count = 1;
        for(int i = k; i < n; i++)
            for(int j = i+1; j < n; j++)
                if(m[j] - m[i] == d)
                {
                    i = j-1;
                    count++;
                    break;
                }
        maxcount = max(count, maxcount);

    }
    return maxcount;


}
int main()
{
    cin >> n;
    int maxAns = 0;
    for (int i=0 ; i < n; i++)
        cin >> m[i];
   // cout << Count(2) << " " << Count(1);
     for(int i = 0 ;i < n; i++)
      for(int j = i; j < n; j++)
        maxAns = max(Count(m[j]-m[i]), maxAns);
    cout << maxAns;
    return 0;
}
