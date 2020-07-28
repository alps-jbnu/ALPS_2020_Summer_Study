#include <bits/stdc++.h>
using namespace std;
int T, N;
string str, token;
deque<int> deq;
string parser;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--) {
        //initialize
        bool sr = true, isError = false;
        deq.clear();
        // input
        cin >> str >> N >> parser;
        // [] 제거
        parser = parser.substr(1, parser.length() - 2);
        // tokenize
        stringstream ss(parser);
        while (getline(ss, token, ','))
        {
            deq.push_back(stoi(token));
        }
    
        for(int i = 0; str[i]; i++) {
            char next = str[i];
            if(next == 'D') {
                if(deq.empty()) {
                    cout << "error\n";
                    isError = true;
                    break;
                }
                else if(sr)
                    deq.pop_front();
                else
                    deq.pop_back();
            }
            else
                sr = !sr;
        }
        if (!isError) {
            cout << '[';
            while (!deq.empty())
            {
                if (sr) {
                    cout << deq.front();
                    deq.pop_front();
                }
                else {
                    cout << deq.back();
                    deq.pop_back();
                }
                if (!deq.empty())
                    cout << ',';
            }
            cout << "]\n";
        }
    }
}