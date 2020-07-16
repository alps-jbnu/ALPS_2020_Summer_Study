#ifndef ONLINE_JUDGE
#pragma warning(disable:4996)
#endif

#include <cstdio>
#include <deque>

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
		char p[MAX];
		bool bReversed = false;
		bool bError = false;

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

		for (int i = 0; p[i] != '\0'; ++i)
		{
			if (p[i] == 'R')
			{
				bReversed = !bReversed;
			}
			else if (p[i] == 'D')
			{
				if (dq.empty())
				{
					bError = true;
					break;
				}
				if (bReversed)
				{
					dq.pop_back();
				}
				else
				{
					dq.pop_front();
				}
			}
		}

		if (bError)
		{
			puts("error");
			continue;
		}

		putchar('[');
		if (bReversed)
		{
			while (!dq.empty())
			{
				printf("%hhd", dq.back());
				if (dq.size() > 1)
				{
					putchar(',');
				}
				dq.pop_back();
			}
		}
		else
		{
			while (!dq.empty())
			{
				printf("%hhd", dq.front());
				if (dq.size() > 1)
				{
					putchar(',');
				}
				dq.pop_front();
			}
		}
		putchar(']');

		putchar('\n');
	}

	return 0;
}
