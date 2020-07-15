#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	long long ans = 0;
	queue<string> q;
	vector<int> v(20, 0);

	cin >> N >> K;

	while (N--) {
		string name;
		cin >> name;
		q.push(name);
		v[name.length()]++;
		if (v[name.length()] > 1) ans += v[name.length()] - 1;
		if (q.size() == K + 1) {
			v[q.front().length()]--;
			q.pop();
		}
	}
	cout << ans << endl;
}