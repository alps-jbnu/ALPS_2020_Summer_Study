#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int n, m;
int arr[501][501];
bool check[501][501];

int n_x[4] = { 0,1,0,-1 };
int n_y[4] = { 1,0,-1,0 };


int solve(int w, int h, int cnt) {
	if (cnt == 4) return arr[w][h];

	int sum = 0;

	for (int i = 0; i < 4; i++) {
		int nx = w + n_x[i];
		int ny = h + n_y[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && !check[nx][ny]) {
			check[nx][ny] = true;
			sum = max(sum, arr[w][h] + solve(nx, ny, cnt + 1));
			check[nx][ny] = false;
		}
	}
	return sum;
}

int ex(int w, int h) {
	int ans = 0;
	if (w <= n - 1 && h > 0 && h < m - 1) ans = max(ans, arr[w][h] + arr[w - 1][h] + arr[w][h - 1] + arr[w][h + 1]);
	if (w < n - 1 && h > 0 && h < m - 1) ans = max(ans, arr[w][h] + arr[w + 1][h] + arr[w][h - 1] + arr[w][h + 1]);
	if (w > 0 && w < n - 1 && h >0) ans = max(ans, arr[w][h] + arr[w - 1][h] + arr[w + 1][h] + arr[w][h - 1]);
	if (w > 0 && w < n - 1 && h < n - 1) ans = max(ans, arr[w][h] + arr[w - 1][h] + arr[w + 1][h] + arr[w][h + 1]);
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> arr[i][j];

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			check[i][j] = true;
			ans = max(ans, solve(i, j, 1));
			ans = max(ans, ex(i, j));
			check[i][j] = false;
		}
	}
	cout << ans;
	return 0;
}
