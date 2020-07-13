#include<iostream>
#include<stack>
#include<string>
using namespace std;

int solve() {
	int now = 1, ans = 0;
	stack<char> st;
	string w;
	cin >> w;

	for (int i = 0; i < w.length(); i++) {
		if (w[i] == '(') {
			now *= 2;
			st.push(w[i]);
		}
		else if (w[i] == '[') {
			now *= 3;
			st.push(w[i]);
		}
		else if (w[i] == ')') {
			if (!st.empty() && st.top() == '(') {
				if (w[i - 1] == '(') ans += now;
				st.pop();
				now /= 2;
			}
			else return -1;
		}
		else if (w[i] == ']') {
			if (!st.empty() && st.top() == '[') {
				if (w[i - 1] == '[') ans += now;
				st.pop();
				now /= 3;
			}
			else return -1;
		}
	}
	if (!st.empty()) return -1;
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int ans = solve();
	
	if (ans == -1) cout << 0;
	else cout << ans;
	return 0;
}
