#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int arr[301][301], cop[301][301];
bool v[301][301];
int n_x[4] = { 0,1,0,-1 };
int n_y[4] = { 1,0,-1,0 };
int x, y;


void mov(int w, int h)
{
	v[w][h] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(w, h));
	while (!q.empty()) {
		int nw = q.front().first;
		int nh = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = nw + n_x[i];
			int ny = nh + n_y[i];
			if (!v[nx][ny] && arr[nx][ny] && nx >= 0 && nx < x && ny >= 0 && ny < y) {
				v[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int find(int w, int h)
{
	int c = 0;
	for (int i = 0; i < 4; i++) {
		int nx = w + n_x[i];
		int ny = h + n_y[i];
		if (nx >= 0 && nx < x && ny >= 0 && ny < y && arr[nx][ny] == 0) c++;
	}
	return c;
}

int melt()
{
	int cnt = 0;

	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++) v[i][j] = false;

	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++) cop[i][j] = max(0,arr[i][j]-find(i,j));

	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			arr[i][j] = cop[i][j];

	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			if (arr[i][j] != 0 && v[i][j] == false) {
				cnt++;
				mov(i, j);
			}
		
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int ma = 0;
	bool check = false;
	cin >> x >> y;
	for (int i = 0; i < x; i++) 
		for (int j = 0; j < y; j++) {
			cin >> arr[i][j];
			ma = max(arr[i][j], ma);
		}
		

	for (int i = 1; i; i++) {
		int num = melt();
		if (num >= 2) {
			cout << i;
			break;
		}
		if (num == 0) {
			cout << 0;
			break;
		}
	}
	return 0;
}
