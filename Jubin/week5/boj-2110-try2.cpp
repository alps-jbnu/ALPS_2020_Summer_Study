#include <iostream>
#include <algorithm>

using namespace std;

enum
{
	MAX = 200000
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	int C;
	int pos[MAX];

	cin >> N >> C;

	for (int n = 0; n < N; ++n)
	{
		cin >> pos[n];
	}

	sort(pos, pos + N);

	int low = 1;
	int high = pos[N - 1] - pos[0];

	while (low + 1 < high)
	{
		int mid = (low + high) / 2;
		int lastPos = pos[0];
		int count = 1;

		for (int i = 1; i < N; ++i)
		{
			int dist = pos[i] - lastPos;
			if (dist >= mid)
			{
				++count;
				lastPos = pos[i];
			}
		}

		if (count >= C)
		{
			low = mid;
		}
		else
		{
			high = mid;
		}
	}

	cout << low;

	return 0;
}
