#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");

int dp[110][10010];
int main(){

	int N, M;
	in >> N >> M;
	vector<int> w(N+1), c(N+1);
	for (int i = 0; i < N; ++i){
		cin >> w[i + 1]  >> c[i+1];
	}

	dp[0][0] = 0;
	for (int i = 1; i < N; ++i){
		dp[i][0] = 0;
	}
	for (int i = 1; i <= M; ++i){
		dp[0][i] = 0;
	}
	vector<int> pr(100100);

	for (int i = 1; i < N + 1; ++i){
		for (int j = 1; j <= M; ++j){
			dp[i][j] = 0;
			if (j - w[i] >= 0){
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + c[i]);
			}
			else{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	int pos = N;

	vector<int> ans;
	int sum = 0;

	while (pos!=0){
		if (dp[pos][M] == dp[pos - 1][M]){
			pos--;
			continue;
		}

		else{

            sum+=c[pos];
			ans.push_back(pos);
			int z = dp[pos][M] - dp[pos - 1][M];
			M -= w[pos];
			pos--;

		}
	}

	reverse(ans.begin(), ans.end());
	out << ans.size() << " " << sum << endl;
	for (int i = 0; i < ans.size(); ++i){
		out << ans[i] << " ";
	}
	return 0;
}
