#include<iostream>
#include<deque>
#include<queue>
using namespace std;

int cnt;
deque<int> dq;

void solve(int num) {
	if (dq.front() == num) {
		dq.pop_front();
		return;
	}
	else {
		deque<int> x = dq;
		deque<int> y = dq;
		int cnt1 = 0, cnt2 = 0, n;
		while (x.front()!=num) {
			n = x.front();
			x.pop_front();
			x.push_back(n);
			cnt1++;
		}
		while (y.front() != num) {
			n = y.back();
			y.pop_back();
			y.push_front(n);
			cnt2++;
		}
		if (cnt1 >= cnt2) {
			cnt += cnt2;
			dq = y;
		}
		else {
			cnt += cnt1;
			dq = x;
		}
		dq.pop_front();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	deque<int> q;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		dq.push_back(i);
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		solve(num);
	}
	cout << cnt;
	return 0;
}
