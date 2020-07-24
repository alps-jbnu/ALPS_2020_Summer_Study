#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = n, cnt;
    sort(lost.begin(), lost.end(), greater<int>());
    sort(reserve.begin(), reserve.end(), greater<int>());
    for (int i = 0; i < lost.size(); i++) {
        for (auto j = 0; j != reserve.size(); j++) {
            if (lost[i] == reserve[j]) {
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
                i--;
                break;
            }
        }
    }
    while (!lost.empty()) {
        if (reserve.empty()) {
            answer -= lost.size();
            break;
        }
        while (reserve.back() < lost.back() - 1)
            reserve.pop_back();
        cnt = reserve.back() - lost.back();
        if (abs(cnt) > 1)
            answer--;
        else
            reserve.pop_back();
        lost.pop_back();
    }
    return answer;
}