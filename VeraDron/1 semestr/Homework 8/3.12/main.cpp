#include <iostream>
#include <vector>

using namespace std;

vector <int> z_function(string s)
{
    int n=s.size();
    vector<int> z(n);
    for(int i = 1,l = 0,r = 0; i < n; ++i)
    {
        if(i <= r)
            z[i] = min(r - i + 1,z[i - l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i,  r = i+z[i]-1;
    }
    return z;
}
int ans(string s, string p)
{
    int Ans = 0;
    s = p + "$" + s;
    vector<int> v = z_function(s);
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] == p.size()) Ans += i-p.size() - 1;
    }
    return Ans;
}
int main()
{

    string s,p;
    cin >> s >> p;
    cout<<ans(s,p);
    return 0;
}
