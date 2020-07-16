// AC

#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

enum
{
	SIZE = 500001
};

int main()
{
	int N;
	vector<int> heights(SIZE);
	vector<int> ans(SIZE);

	stack<int> st; // position

	scanf("%d", &N);

	for (int n = 1; n <= N; ++n)
	{
		int h;
		scanf("%d", &h);
		heights[n] = h;
	}

	for (int n = 1; n <= N; ++n)
	{
		if (st.empty())
		{
			ans[n] = 0;
			st.push(n);
			continue;
		}

		if (heights[st.top()] > heights[n])
		{
			ans[n] = st.top();
			st.push(n);
			continue;
		}

		while (!st.empty() && heights[st.top()] <= heights[n])
		{
			st.pop();
		}

		ans[n] = st.empty() ? 0 : st.top();

		st.push(n);
	}

	for (int n = 1; n <= N; ++n)
	{
		printf("%d ", ans[n]);
	}

	return 0;
}
