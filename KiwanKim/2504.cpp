#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <algorithm>
#include <stack>
#include <stdio.h>
using namespace std;
 
#define INF 987654321
#define INF2 1e9;
#define MOD 998244353
#define pii pair<int,int>
#define pll pair<long long,long long>
typedef long long ll;

stack<int> st;
stack<bool> st2;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    string tmp;
    int inner;
    cin >> tmp;

    for(int i=0;i<tmp.length();i++){
        if(tmp[i] == '(' || tmp[i] == '['){
            st.push(tmp[i]);
            st2.push(true);
        }else if(tmp[i] == ')'){
            if(st.empty()){
                cout << 0;
                return 0;
            }
            inner = 0;
            if((char)st.top() == '(' && st2.top() == true)
                inner = 1;
            
            while(true){
                if(st.empty()){
                    cout << 0;
                    return 0;
                }
                if((char)st.top() == '['){
                    cout << 0;
                    return 0;
                }else if((char)st.top() == '('){
                    st.pop();
                    st2.pop();
                    st.push(inner*2);
                    st2.push(false);
                    break;
                }else{
                    inner += st.top();
                    st.pop();
                    st2.pop();
                }
            }
        }else if(tmp[i] == ']'){
            if(st.empty()){
                    cout << 0;
                    return 0;
                }
            inner = 0;
            if((char)st.top() == '[' && st2.top() == true)
                inner = 1;

            while(true){
                if(st.empty()){
                    cout << 0;
                    return 0;
                }
                if((char)st.top() == '('){
                    cout << 0;
                    return 0;
                }else if((char)st.top() == '['){
                    st.pop();
                    st2.pop();
                    st.push(inner*3);
                    st2.push(false);
                    break;
                }else{
                    inner += st.top();
                    st.pop();
                    st2.pop();
                }
            }
        }
    }
    int ans = 0;
    while(!st.empty()){
        ans += st.top();
        if(st2.top()==true){
            cout << 0;
            return 0;
        }
        st.pop();
        st2.pop();
    }
    cout << ans;
    
    return 0;
}
