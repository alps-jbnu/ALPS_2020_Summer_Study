#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answer) {
	vector<vector<int>> solution = {
		{ 1, 2, 3, 4, 5 },
		{ 2, 1, 2, 3, 2, 4, 2, 5 },
		{ 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 }
	};
	vector<int> index = { 0, 0, 0 };
	vector<pair<int, int>> cnt = {
		make_pair(0, 1), make_pair(0, 2), make_pair(0, 3)
	};
	for (int i = 0; i < answer.size(); i++) {
		int ans = answer[i];
		for (int j = 0; j < solution.size(); j++) {
			if (ans == solution[j][index[j]++]) {
				cnt[j].first++;
			}
			if (index[j] == solution[j].size())
				index[j] = 0;
		}
	}
	sort(cnt.begin(), cnt.end(), greater<pair<int ,int>>());

	vector<int> ans;
	ans.push_back(cnt[0].second);
	for (int i = 1; i < cnt.size(); i++) {
		if (cnt[i].first == cnt[0].first)
			ans.push_back(cnt[i].second);
	}
	sort(ans.begin(), ans.end());
	return ans;
}
int main() {
	vector<int> A;
	for (int i = 0, num; i < 10; i++) {
		cin >> num;
		A.push_back(num);
	}
	vector<int> ans = solution(A);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
}