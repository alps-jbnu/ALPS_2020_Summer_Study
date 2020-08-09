#include <cstdio>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

int N;

enum
{
	SIZE = 100
};

bool IsValid(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < N;
}

void dfs(short current, const vector<vector<short>>& vertex, bitset<SIZE * SIZE>& visited)
{
	visited[current] = true;

	for (short next : vertex[current])
	{
		if (!visited[next])
		{
			dfs(next, vertex, visited);
		}
	}
}

int main()
{
	char maxHeight = 0;
	char heights[SIZE][SIZE];
	
	const int ox[] = {0, 0, 1, -1};
	const int oy[] = {1, -1, 0, 0};
	
	scanf("%d", &N);
	
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			scanf("%hhd", heights[y] + x);
			maxHeight = std::max(maxHeight, heights[y][x]);
		}
	}
	
	int maxCount = 0;
	
	bitset<SIZE * SIZE> visited;
	
	for (int h = 0; h < maxHeight; ++h)
	{
		vector<vector<short>> vertex;
		vertex.resize(N * N);
		
		for (int y = 0; y < N; ++y)
		{
			for (int x = 0; x < N; ++x)
			{
				visited[y * N + x] = heights[y][x] <= h;
			}
		}
		
		for (int y = 0; y < N; ++y)
		{
			for (int x = 0; x < N; ++x)
			{				
				short index = y * N + x;
				
				if (visited[index])
				{
					continue;
				}
				
				for (int i = 0; i < 4; ++i)
				{
					int nx = x + ox[i];
					int ny = y + oy[i];
					
					if (!IsValid(nx, ny))
					{
						continue;
					}
					
					short newIndex = ny * N + nx;
					
					if (visited[newIndex])
					{
						continue;
					}
					
					vertex[index].push_back(newIndex);
					vertex[newIndex].push_back(index);
				}
			}
		}
		
		int size = 0;
		for (short i = N * N - 1; i >= 0; --i)
		{
			if (!visited[i])
			{
				dfs(i, vertex, visited);
				++size;
			}
		}
		
		maxCount = std::max(maxCount, size);
	}	
	
	printf("%d", maxCount);
	
	return 0;
}
