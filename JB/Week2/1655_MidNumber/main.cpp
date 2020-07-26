#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    priority_queue<int> q;
    priority_queue<int, vector<int>, greater<int> > pq;
    int N, in, cnt = 3;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> in;
        pq.push(in);
        if(pq.size() == cnt) {
            cnt++;
            q.push(pq.top());
            pq.pop();
            
        }
        if (!q.empty() && q.top() > pq.top()) {
            int tmp = pq.top();
            pq.pop();
            pq.push(q.top());
            q.pop();
            q.push(tmp);
        }
        cout << pq.top() << '\n';
    }
}