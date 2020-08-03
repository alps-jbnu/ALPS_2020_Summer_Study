#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
const int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };

int N, M, ans;
bool visited[501][501];
int board[501][501];
int calc(int x, int y, int blocks) { 
	if (blocks == 0) return 0;
	if (x < 0 || x >= M || y < 0 || y >= N || visited[y][x]) return -INF;
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		visited[y][x] = true;
		ret = max(ret, calc(nx, ny, blocks - 1) + board[y][x]);
		visited[y][x] = false;
	}
	return ret;
}

int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> board[y][x];
		}
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			ans = max(ans, calc(x, y, 3));
		}
	}
	cout << ans;
}