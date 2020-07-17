#include <bits/stdc++.h>
using namespace std;
stack<pair<int,int> > st;
vector<int> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int height, N;
    cin >> N;
    vector<int> ans(N); 
    while(cin >> height) v.push_back(height);
    for(int i = 0; i < N; i++) {
        if(st.empty()) st.push(make_pair(v[i], i));
        else if(st.top().first >= v[i]) st.push(make_pair(v[i], i));
        else {
            while(!st.empty() && st.top().first < v[i]) {
                int idx = st.top().second;
                st.pop();
                if(st.empty()) ans[idx] = 0;
                else ans[idx] = st.top().second + 1;
            }
            st.push(make_pair(v[i], i));
        }
    }
    while(!st.empty()) {
        int idx = st.top().second;
        st.pop();
        if (st.empty())
            ans[idx] = 0;
        else
            ans[idx] = st.top().second + 1;
    }
    for(int i = 0; i < N; i++)
        cout << ans[i] << ' ';
}