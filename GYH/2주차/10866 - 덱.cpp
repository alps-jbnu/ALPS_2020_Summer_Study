#include <iostream>
#include <deque>
using namespace std;

int main() 
{
	deque<int> dq;
	int N;
	
	cin >> N;
	//cin.get();
	while(N--)
	{
		string s;
		cin >> s;
		//getchar();
		if(!s.compare("push_front"))
		{
			int x;
			cin >> x;
			dq.push_front(x);
		}
		else if(!s.compare("push_back"))
		{
			int x;
			cin >> x;
			dq.push_back(x);
		}
		else if(!s.compare("pop_front"))
		{
			if(dq.empty())
			{
				cout << "-1" << endl;
				continue;
			}
				
			cout << dq.front() << endl;
			dq.pop_front();
		}
		else if(!s.compare("pop_back"))
		{
			if(dq.empty())
			{
				cout << "-1" << endl;
				continue;
			}
				
			cout << dq.back() << endl;
			dq.pop_back();
		}
		else if(!s.compare("size"))
		{
			cout << dq.size() << endl;
		}
		else if(!s.compare("empty"))
		{
			cout << dq.empty() << endl;
		}
		else if(!s.compare("front"))
		{
			if(dq.empty())
			{
				cout << "-1" << endl;
				continue;
			}
			cout << dq.front() << endl;
		}
		else if(!s.compare("back"))
		{
			if(dq.empty())
			{
				cout << "-1" << endl;
				continue;
			}
			cout << dq.back() << endl;
		}
	}
	
    return 0;
}
