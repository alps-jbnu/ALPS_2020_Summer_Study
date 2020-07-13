#include <cstdio>
#include <deque>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	
	while (T--)
	{
		int N;
		char p[100001];
		bool reversed = false;
		
		deque<char> dq;
		
		scanf("%s", p);
		
		scanf("%d", &N);
		getchar();
		
		char c;
		char x = 0;
		
		while ((c = getchar()) != '\n' && c != EOF)
		{			
			if (c == ',' || c == ']')
			{
				if (x > 0)
				{
					dq.push_back(x);
				}
				x = 0;
			}
			else if (c >= '0' && c <= '9')
			{
				x *= 10;
				x += c - '0';
			}
		}
		
		
		
		if (N == 0)
		{
			dq.clear();
		}
		
		for (int i = 0; p[i] != '\0'; ++i)
		{
			if (p[i] == 'R')
			{
				reversed = !reversed;
			}
			else if (p[i] == 'D')
			{
				if (reversed)
				{
					dq.pop_back();
				}
				else
				{
					dq.pop_front();
				}
			}
		}
		
		if (reversed)
		{
			while (!dq.empty())
			{
				printf("%hhd,", dq.back());
				dq.pop_back();
			}
		}
		else
		{
			while (!dq.empty())
			{
				printf("%hhd,", dq.front());
				dq.pop_front();
			}
		}
		
		putchar('\n');
	}
	

	
	return 0;
}
