#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>vec[10001];
int c[10001];
queue<int>q;
void dfs(int s) {
	c[s] = true;
		cout << s<<" ";
		sort(vec[s].begin(), vec[s].end());
		for (int i = 0; i < vec[s].size(); i++) {
			int num = vec[s].at(i);
			while (!c[num]) {
				dfs(num);
			}
		}
}
void bfs(int start) {
	for (int i = 0; i < 10001; i++) {
		c[i] = 0;
	}
	q.push(start);
	cout << start << " ";
	c[start] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		sort(vec[x].begin(), vec[x].end());
		for (int i = 0; i < vec[x].size(); i++) {
			int y = vec[x].at(i);
			if (!c[y]) {
				q.push(y);
				cout << y << " ";
				c[y] = true;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M, N, V;
	cin >> M >> N >> V;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs(V);
	cout << "\n";
	bfs(V);
	return 0;
}