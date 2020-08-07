#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> v(100001);

bool binarySearch(int begin, int end, int target) {
    while(begin <= end)   {
        int mid = (end + begin) / 2;
        if (v[mid] == target) return true;
        else if (v[mid] < target)
            begin = mid + 1;
        else
            end = mid - 1;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    int input;
    for(int i = 0; i < N; i++)
        cin >> v[i];
    sort(v.begin(), v.begin() + N);   
    cin >> M;
    while(M--) {
        cin >> input;
        if(binarySearch(0, N, input))
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
}