#include<iostream>
#include<queue>
using namespace std;

char arr[51][51];
bool check[51][51][2][2][2][2][2][2];
int x, y;
int n_x[4] = { 0,1,0,-1 };
int n_y[4] = { 1,0,-1,0 };


struct n_status {
	int x = 0;
	int y = 0;
	int cnt = 0;
	int key[6] = { 0, };
};

queue<n_status> q;

int solve(int sx, int sy) {
	n_status n;
	n.x = sx;
	n.y = sy;
	check[sx][sy][0][0][0][0][0][0] = true;
	q.push(n);

	while (!q.empty()) {
		n_status p = q.front();
		q.pop();

		if (arr[p.x][p.y] == '1') return p.cnt;

		if(arr[p.x][p.y]!='.')
			for (int i = 0; i < 6; i++) {
				if (arr[p.x][p.y] == 'a' + i) {
					p.key[i] = true;
					break;
				}
			}


		for (int i = 0; i < 4; i++) {
			int nx = p.x + n_x[i];
			int ny = p.y + n_y[i];

			if (nx >= 0 && nx < x && ny >= 0 && ny < y && arr[nx][ny]!='#' && !check[nx][ny][p.key[0]][p.key[1]][p.key[2]][p.key[3]][p.key[4]][p.key[5]]) {
				if (arr[nx][ny] < 'A' || arr[nx][ny]>'F') {
					n_status w = p;
					w.x = nx;
					w.y = ny;
					w.cnt++;
					q.push(w);
					check[nx][ny][w.key[0]][w.key[1]][w.key[2]][w.key[3]][w.key[4]][w.key[5]] = true;
				}
				else {
					for (int j = 0; j < 6; j++) {
						if (arr[nx][ny] == 'A' + j)
							if (p.key[j]) {
								n_status w = p;
								w.x = nx;
								w.y = ny;
								w.cnt++;
								q.push(w);
								check[nx][ny][w.key[0]][w.key[1]][w.key[2]][w.key[3]][w.key[4]][w.key[5]] = true;
							}
					}
				}
			}

		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int sx, sy;
	cin >> x >> y;
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '0') {
				sx = i;
				sy = j;
				arr[i][j] = '.';
			}
		}

	cout << solve(sx, sy);
	return 0;
}
