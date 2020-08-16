#include <iostream>
#include <bitset>
#include <vector>
#include <queue>

using namespace std;

enum
{
	SIZE = 1001
};

bitset<SIZE> visited;
vector<vector<int>> adj;

void dfs(int cur)
{
	cout << cur << ' ';

	visited[cur] = true;

	for (int next : adj[cur])
	{
		if (!visited[next])
		{
			dfs(next);
		}
	}
}

void bfs(int root)
{
	queue<int> q;

	q.push(root);
	visited[root] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		cout << cur << ' ';

		for (int next : adj[cur])
		{
			if (!visited[next])
			{
				visited[next] = true;
				q.push(next);
			}
		}
	}
}

int main()
{
	int N;
	int M;
	int root;

	cin >> N >> M >> root;

	adj.resize(N + 1);

	for (int i = 0; i < M; ++i)
	{
		int u;
		int v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(root);

	visited.reset();
	cout << '\n';

	bfs(root);

	return 0;
}
