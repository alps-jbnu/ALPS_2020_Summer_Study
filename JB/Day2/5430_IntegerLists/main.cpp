#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, N, in;
    string str, parser;
    deque<int> deq;
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> T;
    while(T--) {
        cin >> str >> N >> parser;
        deq.clear();
        parser = parser.substr(1, parser.length() - 2); // [] 제거
        string token;
        stringstream ss(parser);
        bool sr = true;
        while(getline(ss, token, ',')) {
            deq.push_back(stoi(token));
        }
        cout << '[';
        while(!str.empty()) {
            char next = str[0];
            str = str.substr(1);
            if(next == 'D') {
                if(deq.empty()) cout << "error\n";
                else if(sr) {
                    cout << deq.front() << ' ';
                    deq.pop_front();
                }
                else {
                    cout << deq.back() << ' ';
                    deq.pop_back();
                }
            }
            else sr = !sr;
        }
    }
}