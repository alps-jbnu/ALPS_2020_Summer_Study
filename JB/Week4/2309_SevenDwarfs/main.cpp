#include <bits/stdc++.h>
using namespace std;
vector<int> keys(10), ans;

void solve(int idx, int sum) {
    if(idx >= 9) {
        if(sum == 100 && ans.size() == 7) {
            sort(ans.begin(), ans.end());
            for(int i : ans)
                cout << i << '\n';
            exit(0);
        }
        else return;
    }
    ans.push_back(keys[idx]);
    solve(idx + 1, sum + keys[idx]);
    ans.pop_back();
    solve(idx + 1, sum);
}
int main() {
    for(int i = 0; i < 9; i++)
        cin >> keys[i];
    solve(0, 0);
}