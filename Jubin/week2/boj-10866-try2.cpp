#include <iostream>
#include <list>
#include <cstring>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	list<int> dblist;
	
	char command[11];
	int x;
	
	cin >> N;
	
	while (N--)
	{
		cin >> command;
				
		if (0 == strcmp(command, "push_front"))
		{
			cin >> x;
			dblist.push_front(x);
		}
		else if (0 == strcmp(command, "push_back"))
		{
			cin >> x;
			dblist.push_back(x);
		}
		else if (0 == strcmp(command, "pop_front"))
		{
			if (dblist.empty())
			{
				cout << -1 << '\n';
				continue;
			}
			
			cout << dblist.front() << '\n';
			dblist.pop_front();
		}
		else if (0 == strcmp(command, "pop_back"))
		{
			if (dblist.empty())
			{
				cout << -1 << '\n';
				continue;
			}
			
			cout << dblist.back() << '\n';
			dblist.pop_back();
		}
		else if (0 == strcmp(command, "size"))
		{
			cout << dblist.size() << '\n';
		}
		else if (0 == strcmp(command, "empty"))
		{
			cout << (dblist.empty() ? 1 : 0) << '\n';
		}
		else if (0 == strcmp(command, "front"))
		{
			if (dblist.empty())
			{
				cout << -1 << '\n';
				continue;
			}
			
			cout << dblist.front() << '\n';
		}
		else if (0 == strcmp(command, "back"))
		{
			if (dblist.empty())
			{
				cout << -1 << '\n';
				continue;
			}
			
			cout << dblist.back() << '\n';
		}
	}
	
	return 0;
}
