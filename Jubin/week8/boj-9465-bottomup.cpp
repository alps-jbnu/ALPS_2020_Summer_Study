#include <cstdio>
#include <algorithm>

using namespace std;

enum
{
	MAX = 100001
};

int main()
{
	int T;	
	scanf("%d", &T);
	
	while (T--)
	{
		int N;
		char scores[2][MAX];
		int dp[MAX][3] = {0};
		
		scanf("%d", &N);
		for (int y = 0; y < 2; ++y)
		{
			for (int x = 0; x < N; ++x)
			{
				scanf("%hhd", scores[y] + x);
			}
		}
		
		for (int i = 0; i < N; ++i)
		{
			dp[i + 1][0] = max(dp[i + 1][0], max(dp[i][0], max(dp[i][1], dp[i][2])));
			dp[i + 1][1] = max(dp[i + 1][1], max(dp[i][0], dp[i][2]) + scores[0][i]);
			dp[i + 1][2] = max(dp[i + 1][2], max(dp[i][0], dp[i][1]) + scores[1][i]);
		}
		
		printf("%d\n", max(dp[N][0], max(dp[N][1], dp[N][2])));
	}
	
	return 0;
}
