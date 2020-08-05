#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
long long arr[4][4001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 4; j++) cin >> arr[j][i];

	vector<long long> vec;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) vec.push_back(arr[2][i] + arr[3][j]);

	sort(vec.begin(), vec.end());
	long long ans = 0;
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++) {
			long long mid = arr[0][i] + arr[1][j];
			long long low = lower_bound(vec.begin(), vec.end(), -mid) - vec.begin();
			long long high = upper_bound(vec.begin(), vec.end(), -mid) - vec.begin();

			if (-mid == vec[low]) ans += high - low;
		}
	cout << ans;
	return 0;
}