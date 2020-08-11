#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> v(10001);
int N, M, ans, high;
int binarySearch(ll begin, ll end) {
    while(begin <= end) {
        int mid = (begin + end) / 2LL;
        ll sum = 0;
        for(int i = 0; i < N; i++)
            sum += (v[i] > mid ? mid : v[i]);
        if(sum <= M) {
            ans = mid;
            begin = mid + 1;
            // if(begin >= high) 
            //     break;
        }
        else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> v[i];
        if(high < v[i]) high = v[i];
    }
    cin >> M;
    cout << binarySearch(1, high);
}