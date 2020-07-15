#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> vec[21];
	int n, m;
	long long ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string w;
		cin >> w;
		vec[w.length()].push_back(i);
	}

	for(int i=0;i<21;i++)
		sort(vec[i].begin(), vec[i].end());

	for (int i = 0; i < 21; i++) {
		vec[i].push_back(987654321);
		for (int j = 0; j < vec[i].size() - 1; j++) {
			auto itr = upper_bound(vec[i].begin(), vec[i].end(), vec[i][j] + m);
			itr--;
			auto idx = itr - vec[i].begin();
			ans += idx - j;
		}
	}

	cout << ans;
	return 0;
}
