#include <bits/stdc++.h>
#define ll long long
using namespace std;
int N, ans;
stack<pair<ll, ll> > st;
vector<ll> v;
int main()
{
    cin >> N; // 사람의 수
    ll input;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        v.push_back(input);
    }
    st.push(make_pair(v[0], 0)); // 중복 수는 0 부터 count
    for (int idx = 1; idx < N; idx++)
    {
        pair<ll, ll> now = st.top();    // now는 스택의 탑[높이, 중복 수]
        if (st.empty() || v[idx] < now.first) // 스택이 비어있는 경우 or 스택 탑의 높이가 더 큰 경우 push
            st.push(make_pair(v[idx], 0));
        else if(v[idx] > now.first) // 스택 탑의 높이가 작은 경우 pop & calc
        {
            while(!st.empty() && v[idx] > now.first) {  // 스택 탑의 높이가 커질때까지 반복
                int tmp;
                if(now.second > 0) { // 중복된 경우(중복이 존재하는 경우)
                    tmp = now.second;
                    tmp += 2;  // 중복 시 최소 3명의 사람이 존재하므로
                    ans += (((tmp) * (tmp+1)) / 2) - 1; // n*(n+1)/2
                    st.pop();
                }
                else {  // 중복이 존재하지 않는 경우
                    st.pop();
                    if(st.empty()) {
                        ans += 1;   // 한쪽 끝에 붙어 있는 경우 한 쌍
                        break;
                    }
                    else ans += 2;  // 가운데 존재하는 경우 두 쌍이 나옴
                }
            }
            st.push(make_pair(v[idx], 0));
        }
        else { // 스택의 탑 높이와 현재 높이가 같은 경우 중복 수(second) update
            pair<ll, ll> tmp = now;
            st.pop();
            tmp.second++;
            st.push(tmp);
        }
    }
    if(!st.empty())
        ans += (st.size() - 1); // 스택이 남은 경우 스택 사이즈 -1 쌍만큼 존재(내림차순이므로)
    cout << ans;
}