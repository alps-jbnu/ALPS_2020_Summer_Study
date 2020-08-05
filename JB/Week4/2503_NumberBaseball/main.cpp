#include <bits/stdc++.h>
using namespace std;
int n, ans;
int question[101], arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
bool visited[1001];
pair<int, int> answer[101];

int pos(int number, int p) {
    while(p--)
        number /= 10;
    return number % 10;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> question[i] >> answer[i].first >> answer[i].second;
    do{ //숫자
        int number = 0;
        for(int i = 0; i < 3; i++) {
            number *= 10;
            number += arr[i];
        }
        if(number < 100 || visited[number])
            continue;
        visited[number] = true;
        bool isCorrect = true;
        for(int q = 0; q < n; q++) { // 질문
            int strike = 0, ball = 0;
            for (int i = 0; i < 3; i++) { // 각 질문의 숫자
                for(int j = 0; j < 3; j++) {
                    if(pos(question[q], i) == pos(number, j)) {
                        if(i == j) strike++;
                        else ball++;
                    }
                }
            }
            if(strike != answer[q].first || ball != answer[q].second)
                isCorrect = false;
        }
        if(isCorrect) ans++;
    } while(next_permutation(arr, arr + 9));
    std::cout << ans;
}