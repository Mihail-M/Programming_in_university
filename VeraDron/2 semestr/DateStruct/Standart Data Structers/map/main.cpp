#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main()
{
    ifstream in("dict.txt");
    string key;
    int num;
    map<int, string> dict;
    while (in >> num) {
        in >> key;
        dict[num] = key;
    }
    int n;
    while (cin >> n) {
        if (dict.find(n) != dict.end())
            cout << dict[n] << " ";
    }
    return 0;
}
