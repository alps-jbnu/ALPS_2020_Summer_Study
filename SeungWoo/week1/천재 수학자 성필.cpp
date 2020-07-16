#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);;
	string w;
	stack<int> st;
	cin >> w;
	int now = 0, sum = 0;
	for (int i = 0; i < w.length(); i++) {
		if (w[i] >= '0' && w[i] <= '9') st.push(w[i] - '0');
		else {
			if (w[i] == '+') {
				int s = st.top();
				st.pop();
				int f = st.top();
				st.pop();
				st.push(f + s);
			}
			else if (w[i] == '-') {
				int s = st.top();
				st.pop();
				int f = st.top();
				st.pop();
				st.push(f - s);
			}
			else if (w[i] == '*') {
				int s = st.top();
				st.pop();
				int f = st.top();
				st.pop();
				st.push(f * s);
			}
			else if (w[i] == '/') {
				int s = st.top();
				st.pop();
				int f = st.top();
				st.pop();
				st.push(f / s);
			}
		}
	}
	cout << st.top();
	return 0;
}
