#include <iostream>

using namespace std;

int n;
short dp[10005][3001];

void plus_dp(int n){
    for(int i=0;i<3001;i++){
        dp[n][i] += dp[n-1][i] + dp[n-2][i];//이전 두 피보나치 수의 동일 자리수를 더합니다.
        if(dp[n][i]>=10){//만약 현재 자릿수가 10이상 이면 다음 자릿수에 넘겨줄 수를 계산합니다.
            dp[n][i+1] += (dp[n][i]/10);
            dp[n][i] %= 10;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    if(n==0){
        cout << 0;
        return 0;
    }else if(n==1){
        cout << 1;
        return 0;
    }

    for(int i=0;i<=n;i++){
        if(i==0)
            dp[i][0] = 0;
        else if(i==1)
            dp[i][0] = 1;
        else
            plus_dp(i);
    }

    int idx=3000;
    while(dp[n][idx]==0){//3000자리 부터 차례대로 0이 아닌 수, 즉 현재 n의 시작 자릿수를 찾습니다.
        idx--;
    }
    while(idx>=0){//idx번째 자릿수부터 0의 자릿수까지 차례대로 출력합니다.
        cout << dp[n][idx];
        idx--;
    }

    return 0;
}
