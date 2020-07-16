#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> max_q;
	priority_queue<int, vector<int>, less<int>> min_q;
	
	int n,num;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		if (i % 2 == 1) {
			min_q.push(num);
			if (!max_q.empty() && min_q.top() > max_q.top()) {
				int a = min_q.top();
				min_q.pop();
				int b = max_q.top();
				max_q.pop();
				min_q.push(b);
				max_q.push(a);
			}
		}
		else {
			max_q.push(num);
			if (min_q.top() > max_q.top()) {
				int a = min_q.top();
				min_q.pop();
				int b = max_q.top();
				max_q.pop();
				min_q.push(b);
				max_q.push(a);
			}
		}
		cout << min_q.top() << "\n";
	}
	return 0;
}
