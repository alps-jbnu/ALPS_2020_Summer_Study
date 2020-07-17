#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	deque<int> dq;
	
	char command[11];
	int x;
	
	cin >> N;
	
	while (N--)
	{
		cin >> command;
				
		if (0 == strcmp(command, "push_front"))
		{
			cin >> x;
			dq.push_front(x);
		}
		else if (0 == strcmp(command, "push_back"))
		{
			cin >> x;
			dq.push_back(x);
		}
		else if (0 == strcmp(command, "pop_front"))
		{
			if (dq.empty())
			{
				cout << -1 << '\n';
				continue;
			}
			
			cout << dq.front() << '\n';
			dq.pop_front();
		}
		else if (0 == strcmp(command, "pop_back"))
		{
			if (dq.empty())
			{
				cout << -1 << '\n';
				continue;
			}
			
			cout << dq.back() << '\n';
			dq.pop_back();
		}
		else if (0 == strcmp(command, "size"))
		{
			cout << dq.size() << '\n';
		}
		else if (0 == strcmp(command, "empty"))
		{
			cout << (dq.empty() ? 1 : 0) << '\n';
		}
		else if (0 == strcmp(command, "front"))
		{
			if (dq.empty())
			{
				cout << -1 << '\n';
				continue;
			}
			
			cout << dq.front() << '\n';
		}
		else if (0 == strcmp(command, "back"))
		{
			if (dq.empty())
			{
				cout << -1 << '\n';
				continue;
			}
			
			cout << dq.back() << '\n';
		}
	}
	
	return 0;
}
