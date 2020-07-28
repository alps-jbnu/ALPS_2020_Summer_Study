#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
deque<pii > deq;
priority_queue<pii> pq;
int N, score;

bool cmp(pii &a, pii &b) {
    if(a.second == b.second)
        return a.first > b.first;
    return a.second < b.second;
}

int main () {
    int cnt = 1, ans = 0;
    cin >> N;
    while(cin >> N >> score)
        deq.push_back({score, N});
    sort(deq.begin(), deq.end(), cmp);
    pii now;
    while(!deq.empty()) {
        now = deq.front();
        if(pq.size() < now.second)
            pq.push({-now.first, now.second});
        else if(now.first > -pq.top().first) {
            pq.pop();
            pq.push({-now.first, now.second});
        }
        deq.pop_front();
    }
    while(!pq.empty()) {
        ans += (-pq.top().first);
        pq.pop();
    }
    cout << ans;
}