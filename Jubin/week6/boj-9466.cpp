#include <iostream>
#include <cstring>

using namespace std;

enum
{
    MAX = 100001
};

int N;
int cnt;
int adj[MAX];
bool visited[MAX];
bool escaped[MAX];

void dfs(int cur)
{
    visited[cur] = true;
    
    int next = adj[cur];
    if (visited[next])
    {
        if (!escaped[next])
        {
        	int temp = next;
        	while (temp != cur)
        	{
        		temp = adj[temp];
        		++cnt;
			}
            cnt++;
        }
    }
    else
    {
        dfs(next);
    }

    escaped[cur] = true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        cin >> N;
        for (int i = 1; i <= N; i++)
        {
            cin >> adj[i];
        }

        memset(visited + 1, false, N);
        memset(escaped + 1, false, N);

        cnt = 0;

        for (int i = 1; i <= N; i++)
        {
            if (!visited[i])
            {
                dfs(i);
            }
        }

        cout << N - cnt << '\n';
    }
}
