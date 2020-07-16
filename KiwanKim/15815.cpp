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
int calc(int one,int two, char op){
    if(op=='*'){
        return one*two;
    }else if(op=='/'){
        return one/two;
    }else if(op=='+'){
        return one+two;
    }else if(op=='-'){
        return one-two;
    }
    return 0;
}
int main(){
    // ios_base :: sync_with_stdio(false);
    // cin.tie(NULL);
    
    string tmp;
    int one,two;
    cin >> tmp;
    for(int i=0;i<tmp.length();i++){
        if(tmp[i]<'0' || tmp[i] >'9'){
            two = st.top();
            st.pop();
            one = st.top();
            st.pop();

            one = calc(one,two,tmp[i]);
            
            st.push(one);
            
        }else{
            st.push(tmp[i]-'0');
            
        }
    }
    cout << st.top();
    return 0;
}
