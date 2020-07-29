#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <algorithm>
#include <stack>
#include <deque>
using namespace std;
 
#define INF 987654321
#define INF2 1e9;
#define MOD 998244353
#define pii pair<int,int>
#define pll pair<long long,long long>
typedef long long ll;
typedef unsigned long long ull;

int N,K;
vector<string> words;
string word;
char antatica[] = {'a','n','c','t','i'};
bool check(vector<int>& permu){
    for(int i=0;i<5;i++){
        if(permu[antatica[i]-'a'] == 0)
            return false;
    }
    return true;
}
int countWord(vector<int>& permu){
    int ret = 0;
    for(int i=0;i<N;i++){
        int j;
        for(j=0;j<words[i].length();j++){
            if(permu[words[i][j]-'a'] == 0)
                break;
        }

        if(j == words[i].length())
            ret++;
    }
    return ret;
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> K;
    for(int i=0;i<N;i++){
        cin >> word;
        words.push_back(word);
    }
    if(K<5){
        cout << 0;
        return 0;
    }

    vector<int> permu;
    for(int i=0;i<26-K;i++)
        permu.push_back(0);

    for(int i=0;i<K;i++)
        permu.push_back(1);
    
    int ans = 0;
    do{
        if(check(permu))
            ans = max(ans,countWord(permu));
    }while(next_permutation(permu.begin(),permu.end()));
    cout << ans;
    return 0;
}
