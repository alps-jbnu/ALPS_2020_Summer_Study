#include<iostream>
#include<algorithm>
using namespace std;

long long n, limit, low, high;
long long arr[10001];

bool solve(long long m) {
	long long sum = 0;
	for (int i = 0; i < n; i++) sum += min(arr[i], m);
	return sum <= limit;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		high = max(arr[i], high);
	}
	cin >> limit;
	long long ans = 0;
	while (low <= high) {
		long long mid = (low + high) / 2;
		if (solve(mid)) {
			ans = max(mid, ans);
			low = mid + 1;
		}
		else high = mid - 1;
	}
	cout << ans;
	return 0;
}