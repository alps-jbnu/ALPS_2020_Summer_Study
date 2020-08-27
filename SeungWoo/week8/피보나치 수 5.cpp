#include<iostream>
using namespace std;

int dp[21];

void solve() {
	dp[1] = 1;
	dp[2] = 1;
	for(int i=3;i<=20;i++) dp[i] = dp[i-2]+dp[i-1];
}

int main() {
	int n;
	cin>>n;
	solve();
	
	cout<<dp[n];
	return 0;
}
