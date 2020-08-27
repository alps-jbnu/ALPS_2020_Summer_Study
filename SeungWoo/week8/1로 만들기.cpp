#include<iostream>
#include<cmath>
using namespace std;

int array[1000001];

void show(int n) {
	int min;
	for(int i=1;i<=n;i++) {
		min = 0;
		if(i==1) array[1] = 0;
		else if(i==2) array[2] = 1;
		else if(i==3) array[3] = 1;
		else {
			if(i%3==0) min=1+array[i/3];
			if(i%2==0)
			{
				if(min==0) min = 1+array[i/2];
				else if(min>1+array[i/2]) min = 1+array[i/2];
			}
			if(min==0) min = 1+array[i-1];
			else if(min>1+array[i-1]) min = 1+array[i-1];
			array[i] = min;
		}
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	show(n);
	cout<<array[n];
	return 0;
}
