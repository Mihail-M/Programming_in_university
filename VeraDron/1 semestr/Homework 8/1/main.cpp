#include <iostream>
#include <fstream>

using namespace std;

// Я мог бы объявить все это локально, но пришлось бы очень усложнить этот простой код
char name[26];

void dfs(int s, char c, int *used, int **g, char *name, int &n, int &start) {
    used[s] = true;
    name[s] = c++;
    for (int i = 0; i < n; i++)
        if(g[s][i] && !used[i])
            dfs(start,'A', used, g, name, n, start);
}

int main() {

    char nameFile[100];
    int start = 0;
    int n = 0, m = 0;
    cout << "Input count of node and edges: ";

    cin >> nameFile >> start;
    ifstream in(nameFile);

    in >> n >> m;
    int used[26];
    char name[26];
    int **g = new int*[n];
    for(int i = 0; i < n; i++)
        g[i] = new int[n];

    cout << "Input graph: ";

    for(int i = 0; i < m; i++) {

        int from = 0;
        int to = 0;
        in >> from >> to;
        g[from - 1][to - 1] = 1;
        g[to - 1][from - 1] = 1;

    }

    dfs(start,'A', used, g, name, n, start);

    cout << "Traverse the graph: ";

    for(int i = 0; i < n; i++)
        if(name[i] != 0)
            cout << i+1 << " - "<< name[i] << endl;

    for (int i = 0; i < n; i++)
        delete g[i];
    delete g;
    return 0;
}
