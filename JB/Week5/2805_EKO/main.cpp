#include <bits/stdc++.h>
using namespace std;
vector<int> v(1000001);
int N, M, ans = 987654321;

int binarySearch(int begin, int end) {
    while(begin <= end) {
        int mid = (begin + end) / 2, sum = 0;
        for(int i = 0; i < N; i++) {
            if(v[i] > mid)
                sum += (v[i] - mid);
        }
        if(sum == M) {
            ans = min(ans, mid);
            begin += 2;
        }
        else if (sum < M)
            end = mid - 1;
        else
            begin = mid + 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> v[i];
    cout << binarySearch(1, 1000001);
}