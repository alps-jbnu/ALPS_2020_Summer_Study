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

int N,M;
vector<int> assets;
vector<int> sumArr;
int calcSum(int maximum){
    int ret = 0;
    int sz = assets.size();
    for(int i=0;i<sz;i++){
        if(assets[i] > maximum){
            ret += maximum*(sz-i);//이값이후로는 모두 maximum보다 클 것이기 때문에 나머지는 모두 maximum으로 산출
            break;
        }
        else
            ret += assets[i];
    }
    return ret;
}
int binarySrch(int s,int e,vector<int> arr){
    if(s>=e)
        return s;
    int mid = (s+e)/2;
    if(calcSum(arr[mid]) < M)
        return binarySrch(mid+1,e,arr);
    else
        return binarySrch(s,mid,arr);
    return 0;
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int tmp;
    int sum = 0;
    for(int i=0;i<N;i++){
        cin >> tmp;
        assets.push_back(tmp);
    }
    sort(assets.begin(),assets.end());
    cin >> M;
    int maximum = assets[binarySrch(0,N-1,assets)];//가장 M에 근접하는 합이 나오는 assets[idx]의 idx 리턴
    while(calcSum(maximum) > M){ 
        maximum--;//찾아가는 과정에서도 이분탐색을 사용하면 좋습니다.
    }
    cout << maximum;
    return 0;
}
