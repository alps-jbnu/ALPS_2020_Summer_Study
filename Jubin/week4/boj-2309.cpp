#include <cstdio>
#include <algorithm>

enum
{
	COUNT = 9
};

int main()
{
	char heights[COUNT];
	int sum = 0;
	
	for (int i = 0; ~scanf("%hhd", heights + i); ++i)
	{
		sum += heights[i];
	}

	for (int i = 0; i < COUNT - 1; ++i)
	{
		for (int j = i + 1; j < COUNT; ++j)
		{
			if (sum - heights[i] - heights[j] == 100)
			{
				heights[i] = 0;
				heights[j] = 0;
				goto found;
			}
		}
	}
	
found:
	
	std::sort(heights, heights + COUNT);
	
	for (int i = 2; i < COUNT; ++i)
	{
		printf("%hhd\n", heights[i]);
	}
	
	return 0;
}
