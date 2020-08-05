#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int arr[300001];

bool solve(int num) {
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		cnt += arr[i] / num;
		if (arr[i] % num) cnt++;
	}
	return cnt <= n;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int low = 1, high = 0, ans = 987654321;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
		high = max(high, arr[i]);
	}
	while (low <= high) {
		int mid = (low + high) / 2;
		if (solve(mid)) {
			ans = min(ans, mid);
			high = mid - 1;
		}
		else low = mid + 1;
	}
	cout << ans;
	return 0;
}