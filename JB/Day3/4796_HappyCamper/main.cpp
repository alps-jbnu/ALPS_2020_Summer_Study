#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long L, P, V, cnt = 0;
    while(cin >> L >> P >> V) {
        if((L == 0) && (P == 0) && (V == 0))
            return 0;
        cnt++;
        long long calc = V % P;
        calc = calc > L ? L : calc;
        cout << "Case " << cnt << ": " << V / P * L + calc << "\n";
    }
}