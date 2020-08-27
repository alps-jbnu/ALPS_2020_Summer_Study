#include<iostream>
#include<algorithm>
using namespace std;

#define INF 987654321
int n, dst;
int arr[101];
int dp[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> dst;
	for (int i = 1; i <= dst; i++) dp[i] = INF;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[arr[i]] = 1;
	}
	sort(arr, arr + n);

	for (int i = arr[0]; i <= dst; i++) {
		for (int j = 0; j < n; j++) {
			if (i - arr[j] >= 0)
				dp[i] = min(dp[i], dp[i - arr[j]] + 1);
			else break;
		}
	}
	if (dp[dst] == INF) cout << -1;
	else cout << dp[dst];
	return 0;
}
