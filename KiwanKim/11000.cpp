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
typedef unsigned long long ull;

int N;
vector<pii> v;
priority_queue<int> pq;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);


    cin >> N;
    for(int i=0;i<N;i++){
        int s,t;
        cin >> s >> t;
        v.push_back({s,t});
    }

    sort(v.begin(),v.end());

    int ans = 0;
    for(int i=0;i<N;i++){
        if(pq.empty())
            pq.push(-v[i].second);
        else if(-pq.top() <= v[i].first){
            pq.pop();
            pq.push(-v[i].second);
        }else{
            pq.push(-v[i].second);
        }
        ans = max(ans,(int)pq.size());
    }   

    cout << ans;

    return 0;
}
