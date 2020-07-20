#include <cstdio>
#include <vector>
#include <algorithm>

enum
{
	MAX_DAY = 1000
};

bool Compare(std::pair<short, char>& p1, std::pair<short, char>& p2)
{
	if (p1.second == p2.second)
	{
		return p1.first < p2.first;
	}
	return p1.second > p2.second;
}

int main()
{
	short N;
	char scores[MAX_DAY + 1] = {0};
	
	scanf("%hd", &N);
	
	std::vector<std::pair<short, char>> assignments;
	assignments.reserve(N);
	
	for (int n = 0; n < N; ++n)
	{
		short d;
		char w;
		scanf("%hd%hhd", &d, &w);
		assignments.push_back(std::make_pair(d, w));
	}
	
	std::sort(assignments.begin(), assignments.end(), Compare);
	
	for (auto& pair : assignments)
	{
		for (short day = pair.first; day > 0; --day)
		{
			if (scores[day] == 0)
			{
				scores[day] = pair.second;
				break;
			}
		}
	}
	
	int maxScore = 0;
	for (int i = 1; i <= MAX_DAY; ++i)
	{
		maxScore += scores[i];
	}
	
	printf("%d", maxScore);
	
	return 0;
}
