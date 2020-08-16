#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int floor;
	int kangho;
	int startlink;
	int up;
	int down;

	cin >> floor >> kangho >> startlink >> up >> down;
	vector<bool> visited(floor + 1);

	queue<pair<int, int>> q;
	q.push(make_pair(kangho, 0));

	while (!q.empty())
	{
		pair<int, int>& p = q.front();

		if (p.first == startlink)
		{
			cout << p.second;
			return 0;
		}

		int upper = p.first + up;
		int lower = p.first - down;
		q.pop();

		if (upper <= floor && !visited[upper])
		{
			q.push(make_pair(upper, p.second + 1));
			visited[upper] = true;
		}

		if (lower > 0 && !visited[lower])
		{
			q.push(make_pair(lower, p.second + 1));
			visited[lower] = true;
		}
	}

	cout << "use the stairs";

	return 0;
}
