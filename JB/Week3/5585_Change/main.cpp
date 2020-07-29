#include <bits/stdc++.h>
using namespace std;
const int arr[] = {500, 100, 50, 10, 5, 1};
int main() {
    int N, cnt = 0, idx = 0;
    cin >> N;
    N = 1000 - N;
    while(N) {
        int available = N / arr[idx];
        if(available) {
            cnt += available;
            N -= available * arr[idx];
        }
        idx++;
    }
    cout << cnt;
}