#include <iostream>

using namespace std;

int n;
int dp[22];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i=0;i<=n;i++){
        if(i==0)
            dp[i] = 0;
        else if(i==1)
            dp[i] = 1;
        else{
            dp[i] = dp[i-1] + dp[i-2];
        }
    }

    cout << dp[n];

    return 0;
}
