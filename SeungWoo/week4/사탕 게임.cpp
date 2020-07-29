#include<iostream>
#include<algorithm>
using namespace std;

int ans,n;
char arr[51][51];

void Swap(int x1, int y1, int x2, int y2) {
	char w = arr[x1][y1];
	arr[x1][y1] = arr[x2][y2];
	arr[x2][y2] = w;
}

void check(int x, int y) {
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (arr[x][i] == arr[x][i - 1]) cnt++;
		else {
			ans = max(cnt, ans);
			cnt = 1;
		}
	}
	ans = max(cnt, ans);

	cnt = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i][y] == arr[i-1][y]) cnt++;
		else {
			ans = max(cnt, ans);
			cnt = 1;
		}
	}
	ans = max(cnt, ans);
}

void change(int x1, int y1, int x2, int y2) {
	Swap(x1, y1, x2, y2);
	check(x1, y2);
	Swap(x1, y1, x2, y2);
}

void solve(int x, int y) {
	if (x > 0) change(x, y, x - 1, y);
	if (x < n - 1) change(x, y, x + 1, y);
	if (y > 0) change(x, y, x, y - 1);
	if (y < n - 1) change(x, y, x, y + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> arr[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			solve(i, j);

	cout << ans;
	return 0;
}