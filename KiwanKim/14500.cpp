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
int score[505][505];

int block[][4][2] = { {{0,0},{0,1},{0,2},{0,3}}, {{0,0},{1,0},{2,0},{3,0}}//작대기
    ,{{0,0},{0,1},{1,0},{1,1}}//뭉툭
    ,{{1,0},{1,1},{0,1},{1,2}},{{0,0},{1,0},{2,0},{1,1}},{{0,0},{0,1},{0,2},{1,1}},{{1,0},{1,1},{0,1},{2,1}}//ㅗ
    ,{{0,0},{1,0},{2,0},{2,1}},{{0,0},{1,0},{0,1},{0,2}},{{0,0},{0,1},{1,1},{2,1}},{{1,0},{1,1},{1,2},{0,2}}//ㄴ
    ,{{2,0},{2,1},{1,1},{0,1}},{{0,0},{1,0},{1,1},{1,2}},{{0,0},{0,1},{1,0},{2,0}},{{0,0},{0,1},{0,2},{1,2}}
    ,{{0,0},{1,0},{1,1},{2,1}},{{1,0},{1,1},{0,1},{0,2}},{{0,1},{1,0},{1,1},{2,0}},{{0,0},{0,1},{1,1},{1,2}}

 };

int srch(int x,int y){
    int ret = 0;
    int sum = 0;
    int tx,ty;
    for(int i=0;i<19;i++){
        sum = 0;
        int j;
        for(j=0;j<4;j++){
            tx = x + block[i][j][0];
            ty = y + block[i][j][1];
            if(tx<= 0 || ty <= 0 || tx>N || ty >M)
                break;
            sum += score[tx][ty];
        }
        if(j==4)
            ret = max(ret,sum);
    }
    return ret;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            cin >> score[i][j];

    int ans = 0;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            ans = max(ans,srch(i,j));

    cout << ans;
    return 0;
}
