#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define INF 987654321
int n, m;
int memory[101];
int pay[101];
int dp[101][10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	int ans = INF;
	for (int i = 0; i < n; i++) cin >> memory[i];
	for (int i = 0; i < n; i++)	cin >> pay[i];

	dp[0][pay[0]] = memory[0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 10001; j++) {
			if (j - pay[i] >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - pay[i]] + memory[i]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			if (dp[i][j] >= m) ans = min(ans, j);
		}
	}
	cout << ans;
	return 0;
}
