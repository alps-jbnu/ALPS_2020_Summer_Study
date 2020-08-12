#include <iostream>
using namespace std;
void dfs(int a, int b, int **c, int m, int n);
int main() {
	int T, M, N, K, X, Y;
	int cnt = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;
		int *ox = new int[K];
		int *oy = new int[K];

		int **cabbage = new int*[M];
		for (int j = 0; j < M; j++) {
			cabbage[j] = new int[N];
			for (int k = 0; k < N; k++) {
				cabbage[j][k] = 0;
			}
		}
	
		for (int j = 0; j < K; j++) {
			cin >> X >> Y;
			ox[j] = X;
			oy[j] = Y;
			cabbage[X][Y] = 1;
		}
		for (int j = 0; j < K; j++) {
			if (cabbage[ox[j]][oy[j]] == 1) {
				dfs(ox[j], oy[j], cabbage, M, N);
				cnt++;
			}
		}
		cout << cnt<<endl;
		cnt = 0;
	}
	return 0;
}
void dfs(int a, int b, int **c, int m, int n) {
	if (a - 1 >= 0) { // аб
		if (c[a - 1][b] == 1) {
			c[a - 1][b] = -1;
			dfs(a - 1, b, c, m, n);
		}
	}
	if (a + 1 < m) { // ©Л
		if (c[a + 1][b] == 1) {
			c[a + 1][b] = -1;
			dfs(a + 1, b, c, m, n);
		}
	}
	if (b + 1 >= 0) { // ╩С
		if (c[a][b + 1] == 1) {
			c[a][b + 1] = -1;
			dfs(a, b + 1, c, m, n);
			
		}
	}
	if (b - 1 < n) { // го
		if (c[a][b - 1] == 1) {
			c[a][b - 1] = -1;
			dfs(a, b - 1, c, m, n);
			
		}
	}
}