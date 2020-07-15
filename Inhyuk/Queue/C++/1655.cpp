#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	priority_queue<int> max_q; //작은 값들 저장, top -> 가운데 값
	priority_queue<int, vector<int>, greater<int>> min_q; //큰 값들 저장
	int N;
	cin >> N;

	while (N--) {
		int value;
		cin >> value;
		if (max_q.size() == 0) max_q.push(value);
		else if (max_q.top() < value) min_q.push(value);
		else max_q.push(value);

		if (min_q.size() > max_q.size()) {
			max_q.push(min_q.top());
			min_q.pop();
		}
		else if(max_q.size() > min_q.size() + 1) {
			min_q.push(max_q.top());
			max_q.pop();
		}

		cout << max_q.top() << '\n';
	}
}