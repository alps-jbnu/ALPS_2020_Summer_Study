#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

enum
{
	MAX = 1000001
};

int dp[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int x;
	cin >> x;

	for (int i = 1; i <= x; ++i)
	{
		dp[i] = INT_MAX;
	}

	dp[1] = 0;
	for (int i = 1; i < x; ++i)
	{
		dp[i + 1] = min(dp[i + 1], dp[i] + 1);
		if (i * 2 < MAX)
		{
			dp[i * 2] = min(dp[i * 2], dp[i] + 1);
		}
		if (i * 3 < MAX)
		{
			dp[i * 3] = min(dp[i * 3], dp[i] + 1);
		}
	}

	cout << dp[x];

	return 0;
}
