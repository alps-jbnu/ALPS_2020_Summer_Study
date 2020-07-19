#include <bits/stdc++.h>
using namespace std;
deque<int> deq;
int main() {
    
    int N, M, search, ans = 0, cmp = 0;
    cin >> N >> M;
    while((N--))
        deq.push_front(N+1);
    while(M--) {
        cin >> search;
        cmp = 0;
        while(search != deq.front()) {
            cmp++;
            deq.push_back(deq.front());
            deq.pop_front();
        }
        (cmp > deq.size()-cmp) ? ans += (deq.size()-cmp) : ans += cmp;
        deq.pop_front();
    }
    cout << ans;
}