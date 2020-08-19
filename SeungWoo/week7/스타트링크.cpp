#include<iostream>
#include<queue>
using namespace std;

int f, s, g, u, d;
bool v[1000001];

int solve() {
	queue<pair<int, int>> q;
	q.push(make_pair(0, s));
	v[s] = true;
	while (!q.empty()) {
		int cnt = q.front().first;
		int now = q.front().second;
		if (now == g) return cnt;
		q.pop();

		if (now + u <= f && v[now + u] == false) {
			v[now + u] = true;
			q.push(make_pair(cnt + 1, now + u));
		}
		if (now - d >= 1 && v[now - d] == false) {
			v[now - d] = true;
			q.push(make_pair(cnt + 1, now - d));
		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> f >> s >> g >> u >> d;
	int ans = solve();
	if (ans == -1) cout << "use the stairs";
	else cout << ans;
	return 0;
}
