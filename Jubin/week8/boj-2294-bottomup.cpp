#include <iostream>

using namespace std;

enum
{
	MAX = 100001
};

int N;
int K;
int coins[100];
int dp[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		cin >> coins[i];
	}
	
	for (int i = 1; i < MAX; ++i)
	{
		dp[i] = MAX;
	}

	for (int i = 0; i < N; ++i)
	{
		int c = coins[i];
		
		for (int j = c; j <= K; ++j)
		{
			dp[j] = min(dp[j], dp[j - c] + 1);
		}
	}
	
	if (dp[K] == MAX)
	{
		dp[K] = -1;
	}
	
	cout << dp[K];

	return 0;
}
