#include <iostream>
#include <algorithm>

using namespace std;

enum
{
	MAX = 1000001
};

int dp[MAX];

int compute(int x)
{
	if (x == 1)
	{
		return 0;
	}
	
	if (dp[x] != -1)
	{
		return dp[x];
	}
	
	int result = compute(x - 1) + 1;
	if (x % 3 == 0)
	{
		result = min(result, compute(x / 3) + 1);
	}
	if (x % 2 == 0)
	{
		result = min(result, compute(x / 2) + 1);
	}
	
	dp[x] = result;
	
	return dp[x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int x;
	cin >> x;
	
    for (int i = 1; i <= x; ++i)
    {
    	dp[i] = -1;
	}
	
	cout << compute(x);
	
	return 0;
}
