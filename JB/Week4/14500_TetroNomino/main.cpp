#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
const int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };

int N, M, ans;
bool visited[501][501];
int board[501][501];
queue<tuple<int, int, int, int> > q;
int calc(int startX, int startY) { 
	int ans = 0;
	visited[startY][startX] = true;
	q.push({ startX, startY, 3, board[startY][startX] });
	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int cnt = get<2>(q.front());
		int sum = get<3>(q.front());
		
		if (cnt == 0) break;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N) //|| visited[ny][nx])
				continue;
			// visited[ny][nx] = true;
			q.push({ nx, ny, cnt - 1, sum + board[ny][nx] });
		}
	}
	while (!q.empty()) {
		ans = max(ans, get<3>(q.front()));
		q.pop();
	}
	return ans;
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
			memset(visited, false, sizeof(visited));
			ans = max(ans, calc(x, y));
		}
	}
	cout << ans;
}