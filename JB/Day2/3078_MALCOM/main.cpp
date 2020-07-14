#include <bits/stdc++.h>
using namespace std;
priority_queue<tuple<int, int, string> > pq;
queue<tuple<int, int, string> > rpq;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K, ans = 0;
    string str;
    cin >> N >> K;
    while(N--) {
        cin >> str;
        pq.push({str.length(), N, str});
    }

    auto f = pq.top();
    pq.pop();
    while(!pq.empty()) {
        auto s = pq.top();
        if (get<0>(f) != get<0>(s) || get<1>(f) - get<1>(s) > K)
        { // 이름의 길이가 다른 경우
            f = s;
            pq.pop();
            while(!rpq.empty()) {
                pq.push(rpq.front());
                rpq.pop();
            }
        }
        else 
        {
            ans++;
            rpq.push(s);
            pq.pop();
        }
        if (pq.empty() && !rpq.empty())
        {
            while (!rpq.empty())
            {
                pq.push(rpq.front());
                rpq.pop();
            }
            f = pq.top();
            pq.pop();
        }
    }
    cout << ans;
}