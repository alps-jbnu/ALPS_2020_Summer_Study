#include <iostream>
#include <queue>
#include <vector>

using namespace std;
	
enum
{
	MAX = 1000	
};

char matrix[MAX][MAX + 1];
bool visited[2][MAX][MAX];

bool IsValid(int y, int x, int height, int width)
{
	return y >= 0 && y < height && x >= 0 && x < width;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	int M;

	const int offset[] = {1, -1, 0, 0};
	int count = 0;
	
	cin >> N >> M;
	
	for (int y = 0; y < N; ++y)
	{
		cin >> matrix[y];
	}
	
	queue<pair<int, char>> q;
	q.push(make_pair(0, 0));
	visited[0][0][0] = true;
	
	while (!q.empty())
	{
		int queueSize = q.size();
		bool found = false;
		
		while (queueSize--)
		{
			pair<int, char>& p = q.front();
			
			int cur = p.first;
			char crashed = p.second;
			int y = cur / M;
			int x = cur % M;
				
			q.pop();
			
			if (y == N - 1 && x == M - 1)
			{
				++count;
				goto found;
			}
			
			for (int i = 0; i < 4; ++i)
			{
				int oy = y + offset[i];
				int ox = x + offset[3 - i];
				
				if (!IsValid(oy, ox, N, M))
				{
					continue;
				}
				
				if (visited[crashed][oy][ox])
				{
					continue;
				}
				
				int newIndex = oy * M + ox;
				
				if (matrix[oy][ox] == '1')
				{
					if (!crashed)
					{
						visited[1][oy][ox] = true;
						q.push(make_pair(newIndex, 1));
					}
				}
				else
				{
					visited[crashed][oy][ox] = true;
					q.push(make_pair(newIndex, crashed));
				}
			}
		}
		
		count++;
	}
	
found:
	
	if (!visited[0][N - 1][M - 1] && !visited[1][N - 1][M - 1])
	{
		count = -1;
	}
	
	cout << count;

	return 0;
}
