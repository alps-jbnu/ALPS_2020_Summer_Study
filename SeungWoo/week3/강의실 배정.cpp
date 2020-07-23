#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	priority_queue<int, vector<int>, greater<int>> q;
	vector<pair<int, int>> v;
	int n;
	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());

	q.push(v[0].second);
	for (int i = 1; i < v.size(); i++) {
		if (v[i].first >= q.top()) {
			q.pop(); 
			q.push(v[i].second);
		}
		else q.push(v[i].second);
	}
	cout << q.size();
	return 0;
}
