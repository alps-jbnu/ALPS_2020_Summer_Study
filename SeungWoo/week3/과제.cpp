#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> vec[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> q;

	int n, a, b, max_cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		max_cnt = max(max_cnt, a);
		vec[a].push_back(b);
	}

	int ans = 0;

	for (int i = max_cnt; i >= 1; i--) {
		for (int j = 0; j < vec[i].size(); j++)
			q.push(make_pair(vec[i][j], i));

		if (!q.empty() && q.top().second < i)
			while (!q.empty() && q.top().second < i)
				q.pop();
		if (!q.empty()) {
			ans += q.top().first;
			q.pop();
		}
	}
	cout << ans;
	return 0;
}
