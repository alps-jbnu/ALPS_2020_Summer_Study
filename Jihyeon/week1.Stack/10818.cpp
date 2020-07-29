#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int>max;
	stack<int>min;

	int n;
	int put;

	cin >> n;
	while (n--) {
		cin >> put;
		if (max.empty() || max.top() < put) {
			max.push(put);
		}
		if (min.empty() || min.top() > put) {
			min.push(put);
		}
	}

	cout << min.top() << " " << max.top();
	return 0;
}