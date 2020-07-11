#include<iostream>
#include<stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<pair<int,int>> st;
	long long n, num, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		
		while (!st.empty() && st.top().first < num) {
			ans += st.top().second;
			st.pop();
		}

		if (st.empty()) st.push(make_pair(num,1));
		else {
			if (st.top().first == num) {
				pair<int, int> p = st.top();
				st.pop();

				ans += p.second;
				if (!st.empty()) ans++;

				p.second++;
				st.push(p);
			}
			else {
				st.push(make_pair(num, 1));
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
