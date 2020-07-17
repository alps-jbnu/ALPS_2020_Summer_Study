#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    stack<pair<char, int> > st;
    for(int idx = 0; str[idx]; idx++) {
        if(str[idx] == '(') st.push(make_pair('(', -1));
        else if(str[idx] == '[') st.push(make_pair('[', -1));
        else if(str[idx] == ')') {
            if(st.empty()) {
                cout << 0;
                return 0;
            }
            int sum = 0;
            pair<char, int>& now = st.top();
            while(!(now.first == '(' && now.second == -1)) {
                if(now.second < 0) {
                    cout << 0;
                    return 0;
                }
                sum += now.second;
                st.pop();
                if (st.empty()) {
                    cout << 0;
                    return 0;
                }
                now = st.top();
            }
            if(sum == 0) sum = 1;
            if (st.empty()){
                cout << 0;
                return 0;
            }
            st.pop();
            st.push(make_pair('(', sum * 2));
        }
        else if(str[idx] == ']') {
            if (st.empty()) {
                cout << 0;
                return 0;
            }
            int sum = 0;
            pair<char, int> &now = st.top();
            while (!(now.first == '[' && now.second == -1))
            {
                if(now.second < 0) {
                    cout << 0;
                    return 0;
                }
                sum += now.second;
                st.pop();
                if (st.empty()) {
                    cout << 0;
                    return 0;
                }
                now = st.top();
            }
            if (sum == 0) sum = 1;
            if(st.empty()) {
                cout << 0;
                return 0;
            }
            st.pop();
            st.push(make_pair('[', sum * 3));
        }
    }
    int ans = 0;
    while(!st.empty()) {
        if(st.top().second < 0) {
            cout << 0;
            return 0;
        }
        ans += st.top().second;
        st.pop();
    }
    cout << ans;
}