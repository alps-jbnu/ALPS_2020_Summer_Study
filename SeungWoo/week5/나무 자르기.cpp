#include <iostream>
using namespace std;

int tr[1000001];

int n;
long long l;

bool check(long long len)
{
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		if ((tr[i] - len) > 0)
			sum += tr[i] - len;
	}
	if (sum >= l) return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long max = 0, min = 1, ans = 0;
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		cin >> tr[i];
		if (tr[i] > max) max = tr[i];
	}
	while (min <= max) {
		long long mid = (max + min) / 2;
		if (check(mid)) {
			if (ans < mid) ans = mid;
			min = mid + 1;
		}
		else max = mid - 1;
	}
	cout << ans;
	return 0;
}
