#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> v(1000001);
ll N, M, ans;

int binarySearch(int begin, int end) {
    ll mid, sum;
    while (begin <= end) {
        mid = (begin + end) / 2, sum = 0;
        for(int i = 0; i < N; i++) {
            if(v[i] > mid)
                sum += (v[i] - mid);
        }
        if(sum < M) {
            end = mid - 1;
        }
        else{
            ans = mid;
            begin = mid + 1;
        }
    }
    // if (begin == end) return begin;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> v[i];
    cout << binarySearch(1, 1000000001);
}