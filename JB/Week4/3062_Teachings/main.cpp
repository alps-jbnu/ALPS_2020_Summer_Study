#include <bits/stdc++.h>
using namespace std;
string words[51];

int N, K, ans;
int main() {

    cin >> N >> K;
    int i = 0;
    cin.clear();
    for(int cnt = 0; cnt < N; cnt++)
        cin >> words[cnt];
    if(K < 5) {
        cout << 0;
        return 0;
    }
    
    for(i = 0; i < N; i++) {
        vector<char> ch{'a', 't', 'n', 'i', 'c'};
        int idx;
        for (idx = 0; idx < words[i].length(); idx++) {
            auto itr = find(ch.begin(), ch.end(), words[i][idx]);
            if(itr == ch.end()) {
                if(ch.size() < K)
                    ch.push_back(words[i][idx]);
                else break;
            }
        }
        if(idx == words[i].length())
            ans++;
    }
    cout << ans;
}