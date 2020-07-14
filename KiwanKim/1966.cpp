#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;
 
#define INF 987654321
#define INF2 1e9;
#define MOD 998244353
#define pii pair<int,int>
#define pll pair<long long,long long>
typedef long long ll;

int N,T,M,tmp;
bool isTarget;
queue<pair<int,bool> > q;
int cnt[10];
int ans;
int nextHigh(){
    for(int i=9;i>0;i--){
        if(cnt[i])
            return i;
    }
    return 0;
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while(T--){
        memset(cnt,0,sizeof(cnt));
        ans = 0;
        cin >> N >> M;
        for(int i=0;i<N;i++){
            cin >> tmp;
            if(i==M)
                isTarget = true;
            else
                isTarget = false;
            
            cnt[tmp]++;
            q.push({tmp,isTarget});
        }
        
        while(!q.empty()){
            auto tmp2 = q.front();
            q.pop();
            if(tmp2.first == nextHigh()){
                cnt[tmp2.first]--;
                ans++;
                if(tmp2.second)
                    cout << ans << '\n';
            }else{
                q.push(tmp2);
            }
        }
    }

    return 0;
}
