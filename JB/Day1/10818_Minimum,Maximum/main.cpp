#include <bits/stdc++.h>
using namespace std;
stack<int> high, low;
int N;
int main() {
    cin >> N;
    int s;
    high.push(-1000001);
    low.push(1000001);
    while(N--) {
        cin >> s;
        if(high.top() < s) high.push(s);
        if(low.top() > s) low.push(s);
    }
    cout << low.top() << ' ' << high.top() << '\n';
}