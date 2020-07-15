#include<iostream>
#include<deque>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	deque<int> dq;
	int n, m;
	string word;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> word;
		if (word == "push_front") {
			cin >> m;
			dq.push_front(m);
		}
		else if (word == "push_back") {
			cin >> m;
			dq.push_back(m);
		}
		else if (word == "pop_front") {
			if (dq.empty()) cout << "-1\n";
			else {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		else if (word == "pop_back") {
			if (dq.empty()) cout << "-1\n";
			else {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		else if (word == "size") cout << dq.size() << "\n";
		else if (word == "empty") cout << dq.empty() << "\n";
		else if (word == "front") {
			if (dq.empty()) cout << "-1\n";
			else cout << dq.front() << "\n";
		}
		else if (word == "back") {
			if (dq.empty()) cout << "-1\n";
			else cout << dq.back() << "\n";
		}
	}
	return 0;
}
