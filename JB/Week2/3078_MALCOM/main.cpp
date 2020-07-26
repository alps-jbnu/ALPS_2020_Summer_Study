#include <bits/stdc++.h>
using namespace std;
int cnt[21];
queue<int> q;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    long long ans = 0;
    string str;
    cin >> N >> K;
    while(N--) {
        cin >> str;
        if(q.size() > K) {
            cnt[q.front()]--;
            q.pop();
        }
        ans += cnt[str.length()];
        q.push(str.length());
        cnt[str.length()]++;
    }
    cout << ans;
}