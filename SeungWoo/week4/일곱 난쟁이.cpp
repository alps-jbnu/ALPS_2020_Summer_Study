#include<iostream>
#include<algorithm>
using namespace std;

int arr[9];
bool check[9], ans;

void solve(int sum, int n, int cnt) {
	if (cnt == 7) {
		if (sum == 100) {
			ans = true;
			for (int i = 0; i < 9; i++)
				if (check[i]) cout << arr[i] << "\n";
			return;
		}
		return;
	}
	
	
	
	for (int i = n; i < 9; i++) {
		if (sum + arr[i] <= 100) {
			check[i] = true;
			solve(sum + arr[i], i + 1, cnt+1);
			if (ans) return;
			check[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	for (int i = 0; i < 9; i++) cin >> arr[i];
	sort(arr, arr + 9);

	for (int i = 0; i < 3; i++) {
		check[i] = true;
		solve(arr[i], i + 1, 1);
		check[i] = false;
	}
	return 0;
}