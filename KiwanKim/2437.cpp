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

int N;
int chu[1005];
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> chu[i];
    }

    sort(chu,chu+N);

    int sum = 0;

    for(int i=0;i<N && sum+1 >= chu[i];i++){
        sum += chu[i];
    }

    cout << sum+1;



    return 0;
}
