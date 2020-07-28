#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
	int N;
	int cnt = 0;
	vector<pair<int, int> >vec;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int S, T;
		cin >> S >> T;
		vec.push_back(make_pair(T, S)); // first 끝나는 시간, second 시작시간
	}
	sort(vec.begin(), vec.end());
	int min = vec[0].first;
	cnt++;
	for (int i = 1; i < N; i++) {
		if (vec[i].second >= min) {
			min = vec[i].first;
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}