#include<iostream>
#include<queue>
using namespace std;

int x, y, t;
int arr[100][100], check[100][100][2];
int n_x[4] = { 0,1,0,-1 };
int n_y[4] = { 1,0,-1,0 };

class mo
{
public:
	int time;
	int ows;
	int w;
	int h;
};

void solve()
{
	queue<mo> q;
	q.push({ 0, 0, 0, 0 });
	check[0][0][0] = true;
	while (!q.empty()) {
		int time = q.front().time;
		int ows = q.front().ows;
		int w = q.front().w;
		int h = q.front().h;

		q.pop();
		if (arr[w][h] == 2) ows = 1;
		if (time > t) {
			cout << "Fail";
			return;
		}
		if (w == x - 1 && h == y - 1) {
			cout << time;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = w + n_x[i];
			int ny = h + n_y[i];

			if (nx >= 0 && nx < x && ny >= 0 && ny < y) {
				if (ows == 1) {
					if (!check[nx][ny][1]) {
						check[nx][ny][1] = check[w][h][1] + 1;
						q.push({ time + 1,ows,nx,ny });
					}
				}
				else {
					if (!check[nx][ny][0] && arr[nx][ny]!=1) {
						check[nx][ny][0] = check[w][h][0] + 1;
						q.push({ time + 1,ows,nx,ny });
					}
				}
			}
		}
	}
	cout << "Fail";
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> x >> y >> t;
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++) cin >> arr[i][j];
	solve();
	return 0;
}
