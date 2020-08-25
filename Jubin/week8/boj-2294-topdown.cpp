#include <iostream>

using namespace std;

enum
{
	RANGE_OUT = 100001
};

int N;
int K;
int coins[100];
int dp[100 + 1][10000 + 1];

int topdown(int i, int amount)
{
	if (i == N)
	{
		return (amount == 0 ? 0 : RANGE_OUT);
	}
	if (dp[i][amount] != -1)
	{
		return dp[i][amount];
	}
	
	int result = topdown(i + 1, amount);
	if (amount >= coins[i])
	{
		result = min(result, topdown(i, amount - coins[i]) + 1);
	}
	dp[i][amount] = result;
	
	return dp[i][amount];
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
	if (count == RANGE_OUT)
	{
		count = -1;
	}
	
	cout << count;

	return 0;
}
