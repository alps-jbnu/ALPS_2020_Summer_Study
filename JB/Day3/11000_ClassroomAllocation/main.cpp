#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<int, int> > vec;
priority_queue<int> pq;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, a, b, cnt = 0;
    cin >> N;
    while(N--) {
        cin >> a >> b;
        vec.push({-a, -b});
    }
    //sort(vec.begin(), vec.end());
    while(!vec.empty()) {
        auto now = vec.top();
        if(pq.empty())
            pq.push(now.second);
        else if(-pq.top() <= -now.first) {
            pq.pop();
            pq.push(now.second);
        }
        else 
            pq.push(now.second);
        if(cnt < pq.size()) cnt = pq.size();
        vec.pop();
    }
    cout << cnt;
}