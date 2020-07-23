#include <iostream>
#include <deque>
using namespace std;
int main()
{
	deque<int> dq;
	int N, M, result=0;
	
	cin >> N >> M;
	
	for(int i=1; i<=N; i++)
	{
		dq.push_back(i);
	}
	
	while(M--)
	{
		int n, index=0;
		cin >> n;
		
		for(int i=1; i<=dq.size(); i++)
		{
			if(dq.front()==n)
			{
				dq.pop_front();
				break;
			}
			int temp = dq.front();
			dq.pop_front();
			dq.push_back(temp);
			index++;
		}
		
		if(index>dq.size()/2)
		{
			index = dq.size()-index+1;
		}
		//cout << "index : " << index << endl;
		result += index;
		//dq�� ������ - front���� ������ index 
	}
	cout << result;
	return 0;
}
