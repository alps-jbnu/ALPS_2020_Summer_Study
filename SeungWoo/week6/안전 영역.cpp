#include<iostream>
#include<algorithm>
using namespace std;

int arr[101][101];
bool v[101][101];
int n_x[4] = { 0, 1, 0, -1 };
int n_y[4] = { 1, 0, -1, 0 };
int n,ans = 1;
int Max = 0, Min = 101;

void reset(int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) v[i][j] = false;
}

void go(int h, int x, int y) {
	v[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + n_x[i];
		int ny = y + n_y[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny<n && v[nx][ny] == false && arr[nx][ny]>h)
			go(h, nx, ny);
	}
}

void test(int num)
{
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] > num && v[i][j] == false) {
				go(num, i, j);
				cnt++;
			}
		}
	}
	ans = max(ans, cnt);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > Max) Max = arr[i][j];
			if (arr[i][j] < Min) Min = arr[i][j];
		}
	for (int i = Min; i <= Max; i++) {
		test(i);
		reset(n);
	}
	cout << ans;
	return 0;
}
