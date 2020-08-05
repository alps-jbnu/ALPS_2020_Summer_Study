#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	int K;
	int D;
	vector<tuple<int, int, int>> rules;
	
	cin >> N >> K >> D;
	rules.reserve(K);
	
	for (int k = 0; k < K; ++k)
	{
		int A;
		int B;
		int C;
		cin >> A >> B >> C;
		rules.push_back(make_tuple(A, B, C));
	}
	
	int low = 1;
	int high = N;
	
	while (low <= high)
	{
		int mid = (low + high) / 2;
		long long count = 0;
		for (int i = 0; i < K; ++i)
		{
			int A = get<0>(rules[i]);
			int B = get<1>(rules[i]);
			int C = get<2>(rules[i]);
			
			int end = min(B, mid);
			if (end >= A)
			{
				count += (end - A) / C;
				++count;
			}
		}
		
		if (count >= D)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	
	cout << high + 1;

	return 0;
}
