#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct element {
    int t;
    int c;
    int ind;
    element(int _t, int _c, int _ind){
        t = _t, c = _c, ind = _ind;
    }
};
bool f(element a, element b){
    return a.c > b.c;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector <element> mas;

    for(int i = 0; i < m; i++) {
        int t1, c1;
        cin >> t1 >> c1;
        mas.push_back(element(t1,c1,i+1));
    }

    sort(mas.begin(), mas.end(), f);
    vector <int> result(m);
    for(int i = 0; i < n; i++)
        result[i] = 0;
    int sum = 0;
    for (int i = 0; i < m; i++){
        for (int j = mas[i].t - 1; j >= 0; j--){
            if (result[j] == 0) {

                result[j] = mas[i].ind;
                if (j <= n)
                    sum += mas[i].c;
                break;
            }
        }
    }
    cout << sum << endl;
    for(int i = 0; i < n; i++)
        cout << result[i] << " ";

    return 0;
}
