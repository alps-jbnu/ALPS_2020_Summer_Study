#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N,K;
string s;
queue<int> q;
int cnt[21];
long long ans = 0;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    for(int i=0;i<N;i++){
        cin >> s;
        if(q.size() > K){
            cnt[q.front()]--;
            q.pop();
        }
        ans += cnt[s.length()];
        q.push(s.length());
        cnt[s.length()]++;
    }
    cout << ans;
    return 0;

}
