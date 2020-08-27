#include <iostream>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;
int map[50][50];
int visited[50][50]; // 방문 표시
int cnt = 0;
queue<pair<int, int> > q;
void bfs(int x, int y,int M,int N) {
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (0 <= a + dx[i] && a + dx[i] < M && 0 <= b + dy[i] && b + dy[i] < N) {
				if (map[a + dx[i]][b + dy[i]] == 1 && visited[a + dx[i]][b + dy[i]] == 0) {
					visited[a + dx[i]][b + dy[i]] = 1; // check
					q.push(make_pair(a + dx[i], b + dy[i]));
				}
			}
		}
	}
}
int main() {
	int T, M, N, K,X,Y;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cnt = 0;
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		cin >> M >> N >> K;
		for (int j = 0; j < K; j++) {
			cin >> X >> Y;
			map[X][Y] = 1;
		}
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 1 && visited[i][j]==0) {
					visited[i][j] = 1; // check
					cnt++;
					bfs(i, j,M,N);
				}
			}
		}
		cout << cnt<<"\n";	
	}
	
	return 0;
}
