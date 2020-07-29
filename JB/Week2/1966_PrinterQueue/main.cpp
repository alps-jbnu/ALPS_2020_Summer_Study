#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int T, N, M, val;
    cin >> T;
    while(T--) {
        priority_queue<pair<int, int>> pq;
        queue<pair<int, int> > q;
        int in, ans = 1;
        cin >> N >> M;
        for(int i = 0; i < N; i++) {
            cin >> in;
            if(i == M) val = in;
            pq.push({in, -i});
            q.push({in, -i});
        }
        pair<int, int> cmp = {val, -M};
        while(q.front() != cmp || pq.top().first != val) {
            if (pq.top().first != q.front().first) {
                q.push(q.front());
                q.pop();
            }
            else {
                ans++;
                q.pop();
                pq.pop();
            }
        }
        cout << ans << '\n';
    }
}