#include <iostream>

using namespace std;


void dfs(int s, int *used, int **g, int n) {
    used[s] = true;
    cout << s+1 << " ";
    for (int i = 0; i < n; i++)
        if(g[s][i] && !used[i])
            dfs(i, used, g, n);
}

int main() {

    int n, m;
    int used[26];

    for(int i = 0; i < 26; i++)
        used[i] = 0;

    cout << "Input count of node and edges: ";
    cin >> n >> m;

    int **g = new int*[n];
    for(int i = 0; i < n; i++)
       g[i] = new int[n];

    for(int i = 0; i < m; i++) {
        int from = 0;
        int to = 0;
        cin >> from >> to;
        g[from - 1][to - 1] = 1;
        g[to - 1][from - 1] = 1;
    }
    cout << "Component: \n";


    for(int i = 0; i < n; i++)
        if(!used[i]) {
            dfs(i, used, g, n);
            cout << endl;
        }
    return 0;
}
