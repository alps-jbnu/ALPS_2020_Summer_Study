#include <iostream>
#include<queue>
using namespace std;

bool al[1001][1001];
bool dcheck[10001];
bool bcheck[10001];

void dfs(int n, int a)
{
	dcheck[n] = true;
	cout << n << ' ';
	for (int i = 1; i <= a; i++) {
		if (i != n)
			if (al[n][i] == true && dcheck[i] == false) dfs(i, a);
	}
}

void bfs(int n, int a)
{
	queue<int> qu;
	int i = 0;

	qu.push(n);
	bcheck[n] = true;
	while (!qu.empty()) {
		int ne = qu.front();
		bcheck[ne] = true;
		cout << ne << ' ';
		qu.pop();

		for (int i = 1; i <= a; i++) {
			if (al[ne][i] == true && bcheck[i] == false) {
				bcheck[i] = true;
				qu.push(i);
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int wh, n, s;
	cin >> wh >> n >> s;
	int st, dt;
	for (int i = 0; i < n; i++) {
		cin >> st >> dt;
		al[st][dt] = true;
		al[dt][st] = true;
	}

	dfs(s, wh);
	cout << "\n";

	bfs(s, wh);


	return 0;
}
