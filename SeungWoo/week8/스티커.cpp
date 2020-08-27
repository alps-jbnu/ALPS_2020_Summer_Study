#include<iostream>
#include<algorithm>
using namespace std;

int arr[2][100001];
int dp[2][100001];
int ans[100001];
void reset(int n)
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < n; j++) dp[i][j] = 0;
}

int solve(int num)
{
	if (num == 1) return max(arr[0][0], arr[1][0]);
	else if (num == 2) return max(arr[0][0] + arr[1][1], arr[1][0] + arr[0][1]);
	else {
		for (int i = 0; i < 2; i++)
			dp[i][0] = arr[i][0];
		dp[0][1] = dp[1][0] + arr[0][1];
		dp[1][1] = dp[0][0] + arr[1][1];
		for (int j = 2; j < num; j++) {
			for (int i = 0; i < 2; i++) {
				if (i == 0) dp[0][j] = arr[0][j] + max(dp[1][j - 1],dp[1][j - 2]);
				else dp[1][j] = arr[1][j] + max(dp[0][j - 1], dp[0][j - 2]);
			}
		}
		return max(dp[0][num - 1], dp[1][num - 1]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < m; k++) cin >> arr[j][k];
		}
		ans[i] = solve(m);
		reset(m);
	}
	for (int i = 0; i < n; i++) cout << ans[i] << "\n";
	return 0;
}
