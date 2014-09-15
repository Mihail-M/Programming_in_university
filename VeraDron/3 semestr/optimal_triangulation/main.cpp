#include <cmath>
#include <algorithm>
#include <iostream>


using namespace std;

const double inf = 1e15;

double x[110], y[110];
double dp[110][110];

double len(int i, int j) {
    return (j - i < 2 ? 0: sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])));
}

int main() {

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];

    for(int k = 2; k < n; k++)
        for(int i = 1; i + k <= n; i++) {
            dp[i][i + k] = inf;
            for(int j = i + 1; j < i + k; j++)
                dp[i][i + k] = min(dp[i][i + k], dp[i][j] + dp[j][i + k] + len(i, j) + len(j, i + k));
        }

    cout << dp[1][n] << endl;
    return 0;
}
