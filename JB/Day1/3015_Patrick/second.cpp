#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll N, ans;
stack<pair<ll, ll>> st;
int main() {
    cin >> N; // 사람의 수
    ll input, dup;
    while(N--) {
        dup = 1;
        cin >> input;
        if(st.empty()) {
            st.push(make_pair(input, dup));
        }
        else {
            while (true) {
                if(st.empty()) {
                    st.push(make_pair(input, dup));
                    break;
                }
                else if(st.top().first <= input) {
                    pair<ll, ll> tmp = st.top();
                    st.pop();
                    ans += tmp.second;
                    if(tmp.first == input) {
                        dup += tmp.second;
                    }
                }
                else if(st.top().first > input) {
                    st.push(make_pair(input, dup));
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans;
}