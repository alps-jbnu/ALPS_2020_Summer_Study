#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <algorithm>
#include <stack>
#include <deque>
using namespace std;
 
#define INF 987654321
#define INF2 1e9;
#define MOD 998244353
#define pii pair<int,int>
#define pll pair<long long,long long>
typedef long long ll;

int money;
int ans;
int coin[] = {500,100,50,10,5,1};
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    ans = 0;
    cin >> money;
    money = 1000-money;
    for(int i=0;i<6;i++){
        ans += money/coin[i];
        money = money%coin[i];
    }

    cout << ans;

    return 0;
}
