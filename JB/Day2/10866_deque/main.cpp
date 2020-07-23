#include <bits/stdc++.h>
using namespace std;
deque<int> deq;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, num;
    string str;
    cin >> N;
    while(N--) {
        cin >> str;
        if(str == "push_front") {
            cin >> num;
            deq.push_front(num);
        }
        else if(str == "push_back") {
            cin >> num;
            deq.push_back(num);
        }
        else if(str == "pop_front") {
            if(deq.empty()) {
                cout << -1 << '\n';
                continue;
            } 
            cout << deq.front() << '\n';
            deq.pop_front();
        }
        else if(str == "pop_back") {
            if (deq.empty()){
                cout << -1 << '\n';
                continue;
            }
            cout << deq.back() << '\n';
            deq.pop_back();
        }
        else if(str == "size") {
            cout << deq.size() << '\n';
        }
        else if(str == "empty") {
            if(deq.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(str == "front") {
            if(!deq.empty())
                cout << deq.front() << '\n';
            else 
                cout << -1 << '\n';
        }
        else if(str == "back") {
            if (!deq.empty())
                cout << deq.back() << '\n';
            else
                cout << -1 << '\n';
        }
    }
}