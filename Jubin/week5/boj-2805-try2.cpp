#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	int M;
	vector<int> heights;
	
	cin >> N >> M;
	
	heights.reserve(N);
	
	for (int n = 0; n < N; ++n)
	{
		int height;
		cin >> height;
		heights.push_back(height);
	}
	
	int low = 0;
	int high = 1e+9;
	
	while (low + 1 < high)
	{
		int mid = (low + high) >> 1;
		long long sum = 0;
		for (int i = 0; i < N; ++i)
		{
			if (mid < heights[i])
			{
				sum += heights[i] - mid;
			}
		}
		
		if (sum >= M)
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
