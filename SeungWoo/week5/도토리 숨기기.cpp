#include<iostream>
#include<algorithm>
using namespace std;

int n, p, d;
pair<int, pair<int, int>> arr[10001];
bool solve(int mid) {
	long long sum = 0;
	for (int i = 0; i < p; i++) {
		int high = min(mid, arr[i].second.first);
		if(high>=arr[i].first)
			sum += ((high - arr[i].first) / arr[i].second.second) + 1;
	}
	return sum>=d;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> p >> d;
	for (int i = 0; i < p; i++)
		cin >> arr[i].first >> arr[i].second.first >> arr[i].second.second;
	
	int ans = 0;
	int low = 0, high = n;
	
	while (low <= high) {
		int mid = (low + high) / 2;
		
		if (solve(mid)) {
			ans = mid;
			high = mid - 1;
		}
		else low = mid + 1;
	}
	cout << ans;
	return 0;
}