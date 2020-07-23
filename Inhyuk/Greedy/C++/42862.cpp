#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> vec(n + 1, 1);
    for (int comp : lost) vec[comp]--;
    for (int comp : reserve) vec[comp]++;
    int ans = 0;
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] >= 1) ans++;
        else if (vec[i] == 0) {
            if (i == 1) {
                if (vec[2] == 2) {
                    vec[2]--;
                    ans++;
                }
            }
            else if (i == vec.size() - 1) {
                if (vec[vec.size() - 2] == 2)
                    ans++;
            }
            else {
                if (vec[i - 1] == 2) {
                    ans++;
                }
                else if (vec[i + 1] == 2) {
                    vec[i + 1]--;
                    ans++;
                }
            }
        }
    }
    return ans;
}

int main() {
    int n, m, k;
    vector<int> lost;
    vector<int> reserve;
    cin >> n >> m >> k;
    for (int i = 0, tmp; i < m; i++) {
        cin >> tmp;
        lost.push_back(tmp);
    }
    for (int i = 0, tmp; i < k; i++) {
        cin >> tmp;
        reserve.push_back(tmp);
    }

    cout << solution(n, lost, reserve) << endl;
}