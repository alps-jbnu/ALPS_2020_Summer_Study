#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int arr[200001];

bool solve(int v) {
	int cnt = 1;
	int now = arr[0];

	for(int i=1;i<n;i++)
		if (arr[i] - now >= v) {
			cnt++;
			now = arr[i];
		}
	if (cnt >= m) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	int low = 1, high = arr[n - 1] - arr[0];
	int ans = 0;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (solve(mid)) {
			ans = max(mid, ans);
			low = mid + 1;
		}
		else high = mid - 1;
	}
	cout << ans;
	return 0;
}