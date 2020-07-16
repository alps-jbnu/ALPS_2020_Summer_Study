#include <stack>
#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	stack<int> nums;
	stack<int> mins;
	stack<int> maxs;
	
	int N;
	cin >> N;
	
	while (N--)
	{
		int x;
		cin >> x;
		
		nums.push(x);
		if (mins.empty() || x < mins.top())
		{
			mins.push(x);
		}
		if (maxs.empty() || x > maxs.top())
		{
			maxs.push(x);
		}
	}
	
	cout << mins.top() << ' ' << maxs.top();
}
