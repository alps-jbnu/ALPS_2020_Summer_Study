#include <bits/stdc++.h>
#define ll long long
using namespace std;
int N;
vector<int> vec;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll ans = 0;
    cin >> N;
    while(cin >> N)
        vec.push_back(N);

    sort(vec.begin(), vec.end());

    for(int i = 0; i < vec.size(); i++) {
        if(ans + 1 < vec[i])
            break;
        ans += vec[i];
    }
    cout << ans + 1;
}
