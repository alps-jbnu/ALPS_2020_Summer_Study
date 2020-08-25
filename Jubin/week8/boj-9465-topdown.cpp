#include <cstdio>
#include <algorithm>

using namespace std;

enum
{
	MAX = 100000
};

int N;
char scores[2][MAX];
int dp[MAX][3];

int sticker(int col, int status)
{
	if (col == N)
	{
		return 0;
	}
	if (dp[col][status] != -1)
	{
		return dp[col][status];
	}
	
	int result = sticker(col + 1, 0);
	if (status != 1)
	{
		result = max(result, sticker(col + 1, 1) + scores[0][col]);
	}
	if (status != 2)
	{
		result = max(result, sticker(col + 1, 2) + scores[1][col]);
	}
	dp[col][status] = result;
	
	return dp[col][status];
}

int main()
{
	int T;	
	scanf("%d", &T);
	
	while (T--)
	{
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
			for (int j = 0; j < 3; ++j)
			{
				dp[i][j] = -1;
			}
		}
		
		printf("%d\n", sticker(0, 0));
	}
	
	return 0;
}
