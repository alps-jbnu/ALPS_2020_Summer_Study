#include <iostream>
#include <stack>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<pair<int,int>> st;
	int n, arr;
	bool check;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr;
		check = false;
		while (!st.empty()) {
			if (st.top().second > arr) {
				cout << st.top().first << ' ';
				check = true;
				break;
			}
			else st.pop();
		}
		if (check == false) cout << "0 ";
		st.push(make_pair(i, arr));
	}
	
	return 0;
}
