#include <iostream>

using namespace std;

enum
{
	MAX = 100001
};

int N;
int K;
int coins[100];
int dp[101][10001];

int topdown(int i, int p)
{
	if (i == N)
	{
		return (p == 0 ? 0 : MAX);
	}
	if (dp[i][p] != -1)
	{
		return dp[i][p];
	}
	
	int result = topdown(i + 1, p);
	if (p >= coins[i])
	{
		result = min(result, topdown(i, p - coins[i]) + 1);
	}
	dp[i][p] = result;
	
	return dp[i][p];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		cin >> coins[i];
	}
	
	for (int i = 0; i <= N; ++i)
	{
		for (int j = 0; j <= K; ++j)
		{
			dp[i][j] = -1;
		}
	}
	
	int count = topdown(0, K);
	if (count == MAX)
	{
		count = -1;
	}
	
	cout << count;

	return 0;
}
