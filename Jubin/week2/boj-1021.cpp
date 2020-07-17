#include <cstdio>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	char N;
	char M;
	scanf("%hhd%hhd", &N, &M);
	
	deque<char> dq;
	for (char n = 1; n <= N; ++n)
	{
		dq.push_back(n);
	}
	
	int totalCount = 0;
	
	for (char m = 0; m < M; ++m)
	{
		char pick;
		scanf("%hhd", &pick);
		
		int count = 0;
		while (pick != dq.front())
		{
			dq.push_back(dq.front());
			dq.pop_front();
			++count;
		}
		
		totalCount += min(count, (int)dq.size() - count);
		dq.pop_front();
	}
	
	printf("%d", totalCount);
	
	return 0;
}
