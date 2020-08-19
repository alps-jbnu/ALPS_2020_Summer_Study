#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

char arr[1001][1001];
bool visit[1001][1001][2];

int x, y;
int n_x[4] = { 0,1,0,-1 };
int n_y[4] = { 1,0,-1,0 };

int test()
{
	priority_queue<pair<int, pair<int, pair<int, int>>>, vector<pair<int, pair<int, pair<int, int>>>>, greater<pair<int, pair<int, pair<int, int>>>>> q;
	q.push(make_pair(1, make_pair(0, make_pair(1, 1))));
	while (!q.empty()) {
		int w = q.top().second.second.first;
		int h = q.top().second.second.second;
		int c = q.top().second.first;
		int cnt = q.top().first;

		q.pop();
		if (w == x && h == y) {
			return cnt;
		}

		for (int i = 0; i < 4; i++) {
			int nx = w + n_x[i];
			int ny = h + n_y[i];
			if (c == 1 && nx > 0 && nx <= x && ny > 0 && ny <= y && arr[nx][ny] == '0' && visit[nx][ny][1] == false) {
				q.push(make_pair(cnt + 1, make_pair(1, make_pair(nx, ny))));
				visit[nx][ny][1] = true;
			}
			else if (c == 0 && nx > 0 && nx <= x && ny > 0 && ny <= y && visit[nx][ny][0] == false) {
				if (arr[nx][ny] == '0') {
					q.push(make_pair(cnt + 1, make_pair(0, make_pair(nx, ny))));
					visit[nx][ny][0] = true;
				}
				else {
					q.push(make_pair(cnt + 1, make_pair(1, make_pair(nx, ny))));
					visit[nx][ny][1] = true;
					visit[nx][ny][0] = true;
				}
			}

		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> x >> y;
	for (int i = 1; i <= x; i++)
		for (int j = 1; j <= y; j++) cin >> arr[i][j];

	cout << test();
	return 0;
}
