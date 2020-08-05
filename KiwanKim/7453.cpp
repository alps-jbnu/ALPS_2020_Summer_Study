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

int n;
int A[4005];
int B[4005];
int C[4005];
int D[4005];
vector<int> sumAB;
vector<int> sumCD;

vector<pii> sumAB2;
vector<pii> sumCD2;

int binarySrch(int s,int e,int num){
    if(s>=e)
        return s;
    int mid = (s+e)/2;

    if(sumCD2[mid].first < num)//미리구해놓은 CD의 합들과 비교
        return binarySrch(mid+1,e,num);
    else
        return binarySrch(s,mid,num);
    return 0;
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sumAB.push_back(A[i]+B[j]);
            sumCD.push_back(C[i]+D[j]);
        }
    }
    sort(sumAB.begin(),sumAB.end());
    sort(sumCD.begin(),sumCD.end());

    for(int i=0;i<sumAB.size();i++){
        int j;
        //연속된 중복된 값을 {숫자,중복된 수}형태로 바꾸어 줍니다.
        for(j=i;j<sumAB.size() && sumAB[i] == sumAB[j] ;j++);

        sumAB2.push_back({sumAB[i],j-i});    
        i=j-1;
    }
    for(int i=0;i<sumCD.size();i++){
        int j;
        for(j=i; j<sumCD.size() && sumCD[i] == sumCD[j];j++);

        sumCD2.push_back({sumCD[i],j-i});
        i=j-1;    
    }
    ll ans = 0;

    for(int i=0;i<sumAB2.size();i++){
        //AB의 합과 더하면 0이 되는 CD의 합을 이분탐색으로 찾습니다.
        int idx = binarySrch(0,sumCD2.size()-1,sumAB2[i].first*-1);
        if(sumAB2[i].first == -1*sumCD2[idx].first){//둘이 합해서 0이 되면 ans에 가능한 경우의 수를 더해줍니다.
            ans += (ll)sumAB2[i].second*(ll)sumCD2[idx].second;//중간에 곱해지는 값이 int범위를 초과하면 overflow가 발생할 수 있습니다.
        }
    }

    cout << ans;



    return 0;
}
