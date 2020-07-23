#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<pair<int, int>> A;
	priority_queue<int, vector<int>, greater<int>> pq;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int first, second;
		cin >> first >> second;
		A.push_back(make_pair(first, second));
	}
	sort(A.begin(), A.end());
	int ans = 0;
	pq.push(A[0].second);
	ans++;
	for (int i = 1; i < N; i++) {
		if (pq.top() <= A[i].first) {
			pq.pop();
			pq.push(A[i].second);
		}
		else {
			pq.push(A[i].second);
			ans++;
		}
	}
	cout << ans << endl;
}