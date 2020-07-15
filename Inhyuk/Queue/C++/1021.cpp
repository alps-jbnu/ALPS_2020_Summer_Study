#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	deque<int> dq;
	queue<int> target;
	int N, K;
	int ans = 0;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) dq.push_back(i);
	for (int i = 0; i < K; i++) {
		int num;
		cin >> num;
		target.push(num);
	}

	while (!target.empty()) {
		if (dq.front() == target.front()) {
			dq.pop_front();
		}
		else {
			deque<int> dq2 = dq;
			int cnt2 = 0;

			deque<int> dq3 = dq;
			int cnt3 = 0;

			//2¹ø¿¬»ê
			while (dq2.front() != target.front()) {
				dq2.push_back(dq2.front());
				dq2.pop_front();
				cnt2++;
			}
			while (dq3.front() != target.front()) {
				dq3.push_front(dq3.back());
				dq3.pop_back();
				cnt3++;
			}
			if (cnt2 < cnt3) {
				ans += cnt2;
				dq = dq2;
				dq.pop_front();
			}
			else {
				ans += cnt3;
				dq = dq3;
				dq.pop_front();
			}
		}
		target.pop();
	}
	cout << ans << endl;
}