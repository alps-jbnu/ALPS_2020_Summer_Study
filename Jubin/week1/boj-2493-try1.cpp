// T.O

#include <cstdio>
#include <stack>

using namespace std;

enum
{
	SIZE = 500000
};

int main()
{
	int N;
	int heights[SIZE];
	scanf("%d", &N);
	stack<int> st;
	
	for (int n = 0; n < N; ++n)
	{
		scanf("%d", heights + n);
	}
	
	for (int n = N - 1; n >= 0; --n)
	{
		bool found = false;
		for (int k = n - 1; k >= 0; --k)
		{
			if (heights[k] > heights[n])
			{
				found = true;
				st.push(k + 1);
				break;
			}
		}
		if (!found)
		{
			st.push(0);
		}
	}
	
	while (!st.empty())
	{
		printf("%d ", st.top());
		st.pop();
	}
	
	return 0;
}
