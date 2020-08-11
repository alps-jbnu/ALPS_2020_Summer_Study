#include <iostream>
#include <cstring>

using namespace std;

enum
{
	MAX = 100001
};

int cycleCount;

void dfs(int cur, const int* adj, bool* visited, bool* escaped)
{
	visited[cur] = true;

	int next = adj[cur];

	if (visited[next])
	{
		if (!escaped[next])
		{
			for (int temp = cur; temp != next; temp = adj[temp])
			{
				++cycleCount;
			}
			//++cycleCount;
		}
	}
	else
	{
		dfs(next, adj, visited, escaped);
	}

	escaped[next] = true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	int adj[MAX];
	bool visited[MAX];
	bool escaped[MAX];

	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;

		memset(visited, false, MAX);
		memset(escaped, false, MAX);

		for (int u = 1; u <= N; ++u)
		{
			cin >> adj[u];
		}

		cycleCount = 0;

		for (int i = 1; i <= N; ++i)
		{
			if (!visited[i])
			{
				dfs(i, adj, visited, escaped);
			}
		}

		cout << N - cycleCount << '\n';
	}

	return 0;
}
