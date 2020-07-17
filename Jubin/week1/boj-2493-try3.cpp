// AC

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	stack<pair<int, int>> st; // <position, height>
	vector<int> heights;
	
	cin >> N;
	heights.reserve(N);
	
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		heights.push_back(x);
	}
	
	for (int i = 0; i < N; i++)
	{
		while (!st.empty() && st.top().second < heights[i])
		{
			st.pop();
		}
		cout << (st.empty() ? 0 : st.top().first) << ' ';
		st.push(make_pair(i + 1, heights[i]));
	}

	return 0;
}
