#include <cstdio>
#include <algorithm>

int main()
{
	int L;
	int P;
	int V;
	
	int t = 0;
	while (true)
	{
		scanf("%d%d%d", &L, &P, &V);
		if (L == 0)
		{
			break;
		}
		
		int days = V / P * L;
		days += std::min(V % P, L);
		
		printf("Case %d: %d\n", ++t, days);
	}	
	
	return 0;
}
