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

int N;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    stack<pll> st;
    ll f,s;
    ll ans = 0;
    while(N--){
        cin >> f;
        s = 1;
        if(st.empty()){
            st.push({f,s});
        }else{
            while(true){
                if(st.empty()){
                    st.push({f,s});
                    break;
                }else if(st.top().first <= f){
                    pll tmp = st.top();
                    st.pop();
                    ans += tmp.second;
                    if(tmp.first == f){
                        s += tmp.second;
                    }
                }else if(st.top().first > f){
                    st.push({f,s});
                    ans++;
                    break;
                }
            }
        }
    }

    cout << ans;

    return 0;
}
