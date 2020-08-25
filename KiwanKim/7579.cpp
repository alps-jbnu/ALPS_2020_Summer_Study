#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[20005];
int N,M;
int m[105];
int c[105];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for(int i=0;i<N;i++)
        cin >> m[i];

    for(int i=0;i<N;i++){
        cin >> c[i];
    }
    
    for(int i=0;i<N;i++){
        for(int j=10000;j>=0;j--){//중복적으로 자기자신이 더해지지 않도록 뒤에서 부터 체크합니다
            if(dp[j+c[i]]<dp[j]+m[i])//j+c[i]비용으로 얻을 수 있는 최대 메모리를 저장하기 위해서
                dp[j+c[i]]=dp[j]+m[i];//이미 저장된 값보다 더 큰 메모리를 저장할 수 있으면 이를 저장
        }
    }

    int ans;
    for(int i=0;i<=10000;i++){//모든 비용을 순회하여
        if(dp[i]>=M){         //해당 비용으로 얻을 수 있는 메모리의 최대값이
            ans = i;          //M을 초과하면 바로 break(최소 비용이므로)
            break;
        }
    }
    cout << ans;
    return 0;
}
